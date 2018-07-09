#include <assert.h>
#include <string.h>
#include "binson_writer.h"

/*
{
  "BBBBCBB?.  @\/;0\" \t? B ? )#????F?      F??      ;?\t BBCBB?.  ": "0x191919191919191919191919191919191919191919191919191919191919191919191d191919191919191919191919191919191919191919191919191919091919191919191919191919191919191919191919ff19191919193519191919421919191919198000000019191919191919191919191919fe1919191914001464191919191919191e1919191919191919191919191919191919fe19191919140014641919191919191919191919191919191919191919a3191919191919191919190119191919371919467ff00000000000001919191919191919191919191919191919191919191919191e19191919191919191946fff00000000000001919191919191919191919191919191919191919191919191919024642"
}
*/
int main(void)
{
    uint8_t expected[825] = "\x40\x15\x18\x02\x42\x42\x42\x42\x43\x42\x42\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\x18\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x2e\x14\x00\x14\x00\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x01\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x40\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x2f\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x10\x19\x19\x19\x19\x19\x19\x3b\x19\x19\x19\x19\x19\x30\x19\x19\x19\x19\x19\x1d\x22\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x14\x01\x00\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x09\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\x19\x19\x00\x19\x19\x19\x19\x19\x19\x19\x42\x19\x13\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x14\x00\x14\x17\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x7f\x19\x19\x19\x19\xef\xbf\xbd\x00\x19\x19\x29\x19\x19\x19\x19\x19\x19\x19\x19\x23\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\x7f\x19\x19\x19\x19\x19\x19\x01\x19\x19\x19\x19\x19\x19\x19\x46\x7f\xef\xbf\xbd\x00\x00\x00\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x19\x46\xef\xbf\xbd\xef\xbf\xbd\x00\x00\x00\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x10\x19\x19\x19\x19\x19\x19\x3b\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\x18\x19\x19\x19\x19\x19\x19\x19\x19\x19\x09\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x01\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x14\x00\x19\x42\x42\x43\x42\x42\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\x18\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1c\x19\x2e\x14\x00\x14\x00\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x01\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x09\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xff\x19\x19\x19\x19\x19\x35\x19\x19\x19\x19\x42\x19\x19\x19\x19\x19\x19\x80\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xfe\x19\x19\x19\x19\x14\x00\x14\x64\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xfe\x19\x19\x19\x19\x14\x00\x14\x64\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xa3\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x01\x19\x19\x19\x19\x37\x19\x19\x46\x7f\xf0\x00\x00\x00\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x19\x19\x19\x46\xff\xf0\x00\x00\x00\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x02\x46\x42\x41";
    uint8_t created[825];
    binson_writer w;
    binson_writer_init(&w, created, sizeof(created));
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_begin(&w);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_name_with_len(&w, "\x42\x42\x42\x42\x43\x42\x42\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\x18\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x2e\x14\x00\x14\x00\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x01\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x40\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x2f\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x10\x19\x19\x19\x19\x19\x19\x3b\x19\x19\x19\x19\x19\x30\x19\x19\x19\x19\x19\x1d\x22\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x14\x01\x00\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x09\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\x19\x19\x00\x19\x19\x19\x19\x19\x19\x19\x42\x19\x13\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x14\x00\x14\x17\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x7f\x19\x19\x19\x19\xef\xbf\xbd\x00\x19\x19\x29\x19\x19\x19\x19\x19\x19\x19\x19\x23\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\x7f\x19\x19\x19\x19\x19\x19\x01\x19\x19\x19\x19\x19\x19\x19\x46\x7f\xef\xbf\xbd\x00\x00\x00\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x19\x46\xef\xbf\xbd\xef\xbf\xbd\x00\x00\x00\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x10\x19\x19\x19\x19\x19\x19\x3b\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\x18\x19\x19\x19\x19\x19\x19\x19\x19\x19\x09\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x01\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x14\x00\x19\x42\x42\x43\x42\x42\x19\x19\x19\x19\x19\x19\x19\x19\x19\xef\xbf\xbd\x18\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1c\x19\x2e\x14\x00\x14\x00\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19", 536);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_bytes(&w, (uint8_t *)"\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1d\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x09\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xff\x19\x19\x19\x19\x19\x35\x19\x19\x19\x19\x42\x19\x19\x19\x19\x19\x19\x80\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xfe\x19\x19\x19\x19\x14\x00\x14\x64\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xfe\x19\x19\x19\x19\x14\x00\x14\x64\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\xa3\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x01\x19\x19\x19\x19\x37\x19\x19\x46\x7f\xf0\x00\x00\x00\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x1e\x19\x19\x19\x19\x19\x19\x19\x19\x19\x46\xff\xf0\x00\x00\x00\x00\x00\x00\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x19\x02\x46\x42", 281);
    assert(w.error_flags == BINSON_ID_OK);
    binson_write_object_end(&w);
    assert(w.error_flags == BINSON_ID_OK);
    assert(memcmp(expected, created, sizeof(expected)) == 0);
    return 0;
}

