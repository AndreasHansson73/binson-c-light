#include <assert.h>
#include <string.h>
#include "binson_parser.h"

/*
{
  "0": "0", 
  "F": {
  }, 
  "G": [
    "0",
    48,
    "0",
    2.580932820096934E24,
    "0x30",
    "F",
    {
    },
    "000000000000000000000000F?      000000000000",
    "0x303030303030303030303030303030303030303030303030",
    "0x303030303030303030303030303030303030303030303030",
    "0x303030303030303030303030303030303030303030303030",
    "0x303030303030303030303030303030303030303030303030",
    "0x303030303030303030303030303030303030303030303030",
    "0x303030303030303030303030303030300f30303030303030",
    48,
    3472328296227680304
  ]
}
*/
int main(void)
{
    uint8_t binson_bytes[262] = "\x40\x14\x01\x30\x14\x01\x30\x14\x01\x46\x40\x41\x14\x01\x47\x42\x14\x01\x30\x10\x30\x14\x01\x30\x46\x30\x30\x30\x30\x45\x14\x01\x45\x18\x01\x30\x14\x01\x46\x40\x41\x14\x32\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x46\x7f\xef\xbf\xbd\x00\x20\x00\x00\x00\x00\x30\x30\x30\x30\x30\x30\x10\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x0f\x30\x30\x30\x30\x30\x30\x30\x10\x30\x13\x30\x30\x30\x30\x30\x30\x30\x30\x43\x41";
    binson_parser p;
    double dval; (void) dval;
    int64_t intval; (void) intval;
    bool boolval; (void) boolval;
    bbuf *rawval; (void) rawval;
    assert(binson_parser_init(&p, binson_bytes, sizeof(binson_bytes)));
    assert(binson_parser_verify(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_go_into_object(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_field_ensure_with_length(&p, "\x30", 1, BINSON_TYPE_STRING));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_string_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30", rawval->bsize) == 0);
    assert(binson_parser_field_ensure_with_length(&p, "\x46", 1, BINSON_TYPE_OBJECT));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_go_into_object(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(!binson_parser_next(&p));
    assert(binson_parser_leave_object(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_field_ensure_with_length(&p, "\x47", 1, BINSON_TYPE_ARRAY));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_go_into_array(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_STRING));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_string_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_INTEGER));
    assert(p.error_flags == BINSON_ID_OK);
    intval = binson_parser_get_integer(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(intval == 48);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_STRING));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_string_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_DOUBLE));
    assert(p.error_flags == BINSON_ID_OK);
    dval = binson_parser_get_double(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(dval == 2.580932820096934E24);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_BYTES));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_bytes_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_STRING));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_string_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x46", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_OBJECT));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_go_into_object(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(!binson_parser_next(&p));
    assert(binson_parser_leave_object(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_STRING));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_string_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x46\x7f\xef\xbf\xbd\x00\x20\x00\x00\x00\x00\x30\x30\x30\x30\x30\x30\x10\x30\x30\x30\x30\x30\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_BYTES));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_bytes_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_BYTES));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_bytes_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_BYTES));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_bytes_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_BYTES));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_bytes_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_BYTES));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_bytes_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_BYTES));
    assert(p.error_flags == BINSON_ID_OK);
    rawval = binson_parser_get_bytes_bbuf(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(memcmp(rawval->bptr, "\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x0f\x30\x30\x30\x30\x30\x30\x30", rawval->bsize) == 0);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_INTEGER));
    assert(p.error_flags == BINSON_ID_OK);
    intval = binson_parser_get_integer(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(intval == 48);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_INTEGER));
    assert(p.error_flags == BINSON_ID_OK);
    intval = binson_parser_get_integer(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(intval == 3472328296227680304);
    assert(binson_parser_leave_array(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(!binson_parser_next(&p));
    assert(binson_parser_leave_object(&p));
    assert(p.error_flags == BINSON_ID_OK);
    return 0;
}

