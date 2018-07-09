#include <assert.h>
#include <string.h>
#include "binson_writer.h"

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
    uint8_t expected[262] = "\x40\x14\x01\x30\x14\x01\x30\x14\x01\x46\x40\x41\x14\x01\x47\x42\x14\x01\x30\x10\x30\x14\x01\x30\x46\x30\x30\x30\x30\x45\x14\x01\x45\x18\x01\x30\x14\x01\x46\x40\x41\x14\x32\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x46\x7f\xef\xbf\xbd\x00\x20\x00\x00\x00\x00\x30\x30\x30\x30\x30\x30\x10\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x0f\x30\x30\x30\x30\x30\x30\x30\x10\x30\x13\x30\x30\x30\x30\x30\x30\x30\x30\x43\x41";
    uint8_t created[262];
    binson_writer w;
    binson_writer_init(&w, created, sizeof(created));
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x30", 1);
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
    binson_write_string_with_len(&w, "\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 48);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_double(&w, 2.580932820096934E24);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x46", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_string_with_len(&w, "\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x18\x18\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x46\x7f\xef\xbf\xbd\x00\x20\x00\x00\x00\x00\x30\x30\x30\x30\x30\x30\x10\x30\x30\x30\x30\x30\x30", 50);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", 24);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", 24);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", 24);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", 24);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30", 24);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x0f\x30\x30\x30\x30\x30\x30\x30", 24);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 48);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 3472328296227680304);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    assert(memcmp(expected, created, sizeof(expected)) == 0);
    return 0;
}

