#include <assert.h>
#include <string.h>
#include "binson_parser.h"

/*
{
  "A": [
    4.83806781712E-312
  ]
}
*/
int main(void)
{
    uint8_t binson_bytes[16] = "\x40\x14\x01\x41\x42\x46\x7f\xf0\x00\xff\xe3\x00\x00\x00\x43\x41";
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
    assert(binson_parser_field_ensure_with_length(&p, "\x41", 1, BINSON_TYPE_ARRAY));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_go_into_array(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(binson_parser_next_ensure(&p, BINSON_TYPE_DOUBLE));
    assert(p.error_flags == BINSON_ID_OK);
    dval = binson_parser_get_double(&p);
    assert(p.error_flags == BINSON_ID_OK);
    assert(dval == 4.83806781712E-312);
    assert(binson_parser_leave_array(&p));
    assert(p.error_flags == BINSON_ID_OK);
    assert(!binson_parser_next(&p));
    assert(binson_parser_leave_object(&p));
    assert(p.error_flags == BINSON_ID_OK);
    return 0;
}

