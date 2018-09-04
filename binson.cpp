#include "binson.hpp"

#include <binson_light.h>

#include <string.h>
#include <stdexcept>

using namespace std;

#define IF_RUNTIME_ERROR(x, msg) if (!(x)) throw std::runtime_error(msg)

const std::array<std::string, 8> BinsonValue::typeToString =
{
    "noneType",
    "boolType",
    "intType",
    "doubleType",
    "stringType",
    "binaryType",
    "objectType",
    "arrayType",
};

Binson & Binson::put(const std::string &key, const BinsonValue &v)
{
    m_items[key] = move(v);
    return *this;
}

Binson & Binson::put(const std::string &key, Binson o)
{
    m_items[key] = BinsonValue(move(o));
    return *this;
}

Binson & Binson::put(const string &key, const uint8_t *data, size_t size)
{
    vector<uint8_t> v(data, data + size);
    m_items[key] = move(BinsonValue(move(v)));
    return *this;
}

const BinsonValue Binson::get(const string &key) const
{
    if (!hasKey(key))
        throw std::out_of_range("Key '" + key + "' does not exist");
    else
        return m_items.at(key);
}

bool Binson::hasKey(const string &key) const
{
    return m_items.find(key) != m_items.end();
}

void Binson::clear()
{
    m_items.clear();
}

bool Binson::seralizeItem(binson_writer *w, const BinsonValue &val) const
{
    bool result = true;
    switch(val.myType())
    {
    case BinsonValue::Types::noneType:
        break;
    case BinsonValue::Types::boolType:
        result = result && binson_write_boolean(w, val.getBool());
        break;
    case BinsonValue::Types::intType:
        result = result && binson_write_integer(w, val.getInt());
        break;
    case BinsonValue::Types::doubleType:
        result = result && binson_write_double(w, val.getDouble());
        break;
    case BinsonValue::Types::stringType:
        result = result && binson_write_string_with_len(w,
                                                        val.getString().data(),
                                                        val.getString().size());
        break;
    case BinsonValue::Types::binaryType:
        result = result && binson_write_bytes(w, val.getBin().data(), val.getBin().size());
        break;
    case BinsonValue::Types::objectType:
        result = result && binson_write_object_begin(w);
        result = result && val.getObject().seralizeItems(w);
        result = result && binson_write_object_end(w);
        break;
    case BinsonValue::Types::arrayType:
        result = result && binson_write_array_begin(w);
        for (auto &arrayValue : val.getArray())
        {
            result = result && seralizeItem(w, arrayValue);
        }
        result = result && binson_write_array_end(w);
        break;
    default:
        throw runtime_error("Unknown binson type");
    }
    return result;
}

bool Binson::seralizeItems(binson_writer *w) const
{
    bool result = true;
    for (auto &item: m_items)
    {
        result = result && binson_write_name(w, item.first.c_str());
        result = result && seralizeItem(w, item.second);
    }
    return result;
}

std::vector<uint8_t> Binson::serialize() const
{
    vector<uint8_t> data;
    data.resize(10000);
    binson_writer w;
    int trys = 5;
    bool result = false;
    do
    {
        if (!binson_writer_init(&w, data.data(), data.size()))
            break;
        result = serialize(&w);
        if (!result)
            data.resize(data.size() * 2);
    } while(!result && trys-- > 0 && w.error_flags == BINSON_ERROR_RANGE);

    if (result)
        data.resize(binson_writer_get_counter(&w));
    else
        data.clear();
    return data;
}

bool Binson::serialize(binson_writer *w) const
{
    bool result = true;
    result = result && binson_write_object_begin(w);
    result = result && seralizeItems(w);
    result = result && binson_write_object_end(w);
    return result;
}

BinsonValue Binson::deseralizeItem(binson_parser *p)
{
    uint8_t t = binson_parser_get_type(p);
    switch(t)
    {
    case BINSON_ID_BOOLEAN:
        return BinsonValue(binson_parser_get_boolean(p) == 0 ? false : true);
        break;
    case BINSON_ID_INTEGER:
        return BinsonValue(binson_parser_get_integer(p));
        break;
    case BINSON_ID_DOUBLE:
        return BinsonValue(binson_parser_get_double(p));
        break;
    case BINSON_ID_STRING:
    {
        bbuf *buf;
        buf = binson_parser_get_string_bbuf(p);
        if (buf)
            return BinsonValue(string(reinterpret_cast<const char*>(buf->bptr), buf->bsize));
        else
            throw runtime_error("Parse error, missing string");
    }
        break;
    case BINSON_ID_BYTES:
    {
        bbuf *buf;
        buf = binson_parser_get_bytes_bbuf(p);
        if (buf)
            return BinsonValue(vector<uint8_t>(buf->bptr, buf->bptr + buf->bsize));
        else
            throw runtime_error("Parse error, missing data");
    }
        break;
    case BINSON_ID_OBJECT:
    {
        IF_RUNTIME_ERROR(binson_parser_go_into_object(p), "Parse error");
        Binson b;
        b.deseralizeItems(p);
        IF_RUNTIME_ERROR(binson_parser_leave_object(p), "Parse error");
        return BinsonValue(b);
    }
        break;
    case BINSON_ID_ARRAY:
    {
        IF_RUNTIME_ERROR(binson_parser_go_into_array(p), "Parse error");
        vector<BinsonValue> array;
        while(binson_parser_next(p))
        {
            array.push_back(deseralizeItem(p));
        }
        IF_RUNTIME_ERROR(binson_parser_leave_array(p), "Parse error");
        return array;
    }
        break;
    default:
        throw runtime_error("Unknown type");
    }
    return BinsonValue();
}

void Binson::deseralizeItems(binson_parser *p)
{
    while(binson_parser_next(p))
    {
        bbuf *buf;
        buf = binson_parser_get_name(p);
        IF_RUNTIME_ERROR(buf != nullptr, "Parse error");
        string name(reinterpret_cast<const char*>(buf->bptr), buf->bsize);
        put(name, deseralizeItem(p));
    }
}

void Binson::deserialize(const std::vector<uint8_t> &data)
{
    binson_parser p;
    clear();

    binson_parser_init(&p, const_cast<uint8_t*>(data.data()), data.size());
    binson_parser_go_into_object(&p);
    deseralizeItems(&p);
    binson_parser_leave_object(&p);
}

void Binson::deserialize(const uint8_t *data, size_t size)
{
    binson_parser p;
    clear();

    IF_RUNTIME_ERROR(binson_parser_init(&p, const_cast<uint8_t*>(data), size), "Parser init error");
    deserialize(&p);
}

void Binson::deserialize(binson_parser *p)
{
    clear();
    IF_RUNTIME_ERROR(binson_parser_reset(p), "Parser reset error");
    IF_RUNTIME_ERROR(binson_parser_go_into_object(p), "Parse error");
    deseralizeItems(p);
    IF_RUNTIME_ERROR(binson_parser_leave_object(p), "Parse error");
}

string Binson::toStr() const
{
    binson_parser p;
    string str;
    str.resize(10000);
    vector<uint8_t> stream = serialize();
    if (stream.empty())
        return string();
    int trys = 5;
    bool result = false;
    size_t size = 0;
    do
    {
        if (!binson_parser_init(&p, stream.data(), stream.size()))
            break;
        size = str.size();
        result = binson_parser_to_string(&p, (char*)str.data(), &size, true);
        if (!result)
            str.resize(size * 2);
    } while(!result && trys-- > 0 && p.error_flags == 0);

    if (!result)
        str.clear();
    else
        str.resize(size);
    return str;
}

BinsonValue::BinsonValue()
{

}

BinsonValue::BinsonValue(bool val)
{
    m_val.b = val;
    m_val.setType(Types::boolType);
}

BinsonValue::BinsonValue(int64_t val)
{
    m_val.i = val;
    m_val.setType(Types::intType);
}

BinsonValue::BinsonValue(int val)
{
    m_val.i = val;
    m_val.setType(Types::intType);
}

BinsonValue::BinsonValue(double val)
{
    m_val.d = val;
    m_val.setType(Types::doubleType);
}

BinsonValue::BinsonValue(string &&val)
{
    m_val.str = move(val);
    m_val.setType(Types::stringType);
}

BinsonValue::BinsonValue(const string &val)
{
    m_val.str = val;
    m_val.setType(Types::stringType);
}

BinsonValue::BinsonValue(const char *str)
{
    m_val.str = string(str);
    m_val.setType(Types::stringType);
}

BinsonValue::BinsonValue(std::vector<uint8_t> &&val)
{
    m_val.bin = move(val);
    m_val.setType(Types::binaryType);
}

BinsonValue::BinsonValue(const std::vector<uint8_t> &val)
{
    m_val.bin = val;
    m_val.setType(Types::binaryType);
}

BinsonValue::BinsonValue(Binson &&val)
{
    m_val.o = move(val);
    m_val.setType(Types::objectType);
}

BinsonValue::BinsonValue(const Binson &val)
{
    m_val.o = val;
    m_val.setType(Types::objectType);
}

BinsonValue::BinsonValue(std::vector<BinsonValue> &&val)
{
    m_val.a = move(val);
    m_val.setType(Types::arrayType);
}

BinsonValue::BinsonValue(const std::vector<BinsonValue> &val)
{
    m_val.a = val;
    m_val.setType(Types::arrayType);
}

BinsonValue BinsonValue::operator=(bool &&val)
{
    m_val.b = move(val);
    m_val.setType(Types::boolType);
    return *this;
}

BinsonValue BinsonValue::operator=(int64_t &&val)
{
    m_val.i = move(val);
    m_val.setType(Types::intType);
    return *this;
}

BinsonValue BinsonValue::operator=(int &&val)
{
    m_val.i = val;
    m_val.setType(Types::intType);
    return *this;
}

BinsonValue BinsonValue::operator=(double &&val)
{
    m_val.d = move(val);
    m_val.setType(Types::doubleType);
    return *this;
}

BinsonValue BinsonValue::operator=(string &&val)
{
    m_val.str = move(val);
    m_val.setType(Types::stringType);
    return *this;
}

BinsonValue BinsonValue::operator=(std::vector<uint8_t> &&val)
{
    m_val.bin = move(val);
    m_val.setType(Types::binaryType);
    return *this;
}

BinsonValue BinsonValue::operator=(Binson &&val)
{
    m_val.o = move(val);
    m_val.setType(Types::objectType);
    return *this;
}

BinsonValue BinsonValue::operator=(std::vector<BinsonValue> &&val)
{
    m_val.a = move(val);
    m_val.setType(Types::arrayType);
    return *this;
}
