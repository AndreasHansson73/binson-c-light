#include <assert.h>
#include <string.h>
#include "binson_writer.h"

/*
{
  "": " ", 
  "": "", 
  "": "", 
  "4": "BBCCCCC "
}
*/
int main(void)
{
    uint8_t expected[120] = "\x40\x14\x00\x14\x01\x00\x14\x01\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x34\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x42\x42\x43\x43\x43\x43\x43\x00\x41";
    uint8_t created[120];
    binson_writer w;
    binson_writer_init(&w, created, sizeof(created));
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "", 0);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x00", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x14", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14", 20);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14", 20);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14", 20);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x14\x14\x14\x14\x14\x14\x34\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14", 20);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x14\x42\x42\x43\x43\x43\x43\x43\x00", 20);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    assert(memcmp(expected, created, sizeof(expected)) == 0);
    return 0;
}

