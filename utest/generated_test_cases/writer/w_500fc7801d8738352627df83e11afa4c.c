#include <assert.h>
#include <string.h>
#include "binson_writer.h"

/*
{
  "0": "0", 
  "B": 48, 
  "C": 1.398043286095289E-76
}
*/
int main(void)
{
    uint8_t expected[25] = "\x40\x14\x01\x30\x14\x01\x30\x14\x01\x42\x10\x30\x14\x01\x43\x46\x30\x30\x30\x30\x30\x30\x30\x30\x41";
    uint8_t created[25];
    binson_writer w;
    binson_writer_init(&w, created, sizeof(created));
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x42", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 48);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x43", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_double(&w, 1.398043286095289E-76);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    assert(memcmp(expected, created, sizeof(expected)) == 0);
    return 0;
}

