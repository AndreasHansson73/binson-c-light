#include <assert.h>
#include <string.h>
#include "binson_writer.h"

/*
{
  "0": [
    {
      "0": [
        
      ]
    },
    [
      
    ],
    {
      "0": [
        
      ]
    },
    [
      1.398043286095289E-76,
      true,
      true,
      false,
      true,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      1.398043286095289E-76,
      808464432,
      808464432,
      808464432,
      808464432,
      808464440,
      808464432,
      808464432,
      808464432,
      807956528,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432,
      808464432
    ],
    808464432,
    808464432,
    808464432,
    808464432,
    808464432,
    1.398043286095289E-76,
    808464432,
    808464432,
    808464432,
    808464432,
    808464440,
    808464432,
    808464432,
    808464432,
    807956528,
    808464432,
    808464432,
    808464432,
    808464432,
    808464432,
    808464432,
    808464432,
    808464432,
    808464432,
    808464432,
    808464432,
    808464432
  ]
}
*/
int main(void)
{
    uint8_t expected[516] = "\x40\x14\x01\x30\x42\x40\x14\x01\x30\x42\x43\x41\x42\x43\x40\x14\x01\x30\x42\x43\x41\x42\x46\x30\x30\x30\x30\x30\x30\x30\x30\x44\x44\x45\x44\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x46\x30\x30\x30\x30\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x38\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x70\x28\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x43\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x46\x30\x30\x30\x30\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x38\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x70\x28\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x12\x30\x30\x30\x30\x43\x41";
    uint8_t created[516];
    binson_writer w;
    binson_writer_init(&w, created, sizeof(created));
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x30", 1);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_double(&w, 1.398043286095289E-76);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_boolean(&w, true);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_boolean(&w, true);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_boolean(&w, false);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_boolean(&w, true);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_double(&w, 1.398043286095289E-76);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464440);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 807956528);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_double(&w, 1.398043286095289E-76);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464440);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 807956528);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_integer(&w, 808464432);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_array_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    assert(memcmp(expected, created, sizeof(expected)) == 0);
    return 0;
}

