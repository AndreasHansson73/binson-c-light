#include <assert.h>
#include <string.h>
#include "binson_writer.h"

/*
{
  "": 0.0, 
  " ": " "
}
*/
int main(void)
{
    uint8_t expected[19] = "\x40\x14\x00\x46\x00\x00\x00\x00\x00\x00\x00\x00\x14\x01\x00\x14\x01\x00\x41";
    uint8_t created[19];
    binson_writer w;
    binson_writer_init(&w, created, sizeof(created));
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "", 0);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_double(&w, 0.0);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x00", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x00", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    assert(memcmp(expected, created, sizeof(expected)) == 0);
    return 0;
}

