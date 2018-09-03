#include <assert.h>
#include <string.h>
#include "binson_writer.h"

/*
{
  "0": "0", 
  "B": [
    
  ], 
  "C": 1.398043286095289E-76, 
  "D": false, 
  "E": "0x30", 
  "F": {
  }, 
  "G": [
    
  ]
}
*/
int main(void)
{
    uint8_t expected[45] = "\x40\x14\x01\x30\x14\x01\x30\x14\x01\x42\x42\x43\x14\x01\x43\x46\x30\x30\x30\x30\x30\x30\x30\x30\x14\x01\x44\x45\x14\x01\x45\x18\x01\x30\x14\x01\x46\x40\x41\x14\x01\x47\x42\x43\x41";
    uint8_t created[45];
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
    binson_write_array_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x43", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_double(&w, 1.398043286095289E-76);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x44", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_boolean(&w, false);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x45", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x46", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x47", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    assert(memcmp(expected, created, sizeof(expected)) == 0);
    return 0;
}

