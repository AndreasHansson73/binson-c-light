/**
 * @file binson_parser_init.c
 *
 * Description
 *
 */

/*======= Includes ==========================================================*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <float.h>
#include <string.h>

#include "binson_defines.h"
#include "binson_parser.h"
#include "utest.h"

/*======= Local Macro Definitions ===========================================*/
/*======= Local function prototypes =========================================*/
/*======= Local variable declarations =======================================*/
/*======= Test cases ========================================================*/

TEST(test_different_depths)
{

    uint8_t buffer[128];

    /* Default depth == 10U */
    BINSON_PARSER_DEF(p10);
    binson_parser_init(&p10, buffer, sizeof(buffer));
    ASSERT_TRUE(p10.max_depth == 10);

    BINSON_PARSER_DEF_DEPTH(p2, 2);
    binson_parser_init(&p2, buffer, sizeof(buffer));
    ASSERT_TRUE(p2.max_depth == 2);

    BINSON_PARSER_DEF_DEPTH(p100, 100);
    binson_parser_init(&p100, buffer, sizeof(buffer));
    ASSERT_TRUE(p100.max_depth == 100);

    uint8_t two_levels[] = {
        0x40,
        0x14, 0x01, 0x41,
            0x40,
                0x14, 0x01, 0x41, 0x14, 0x01, 0x41,
            0x41,
        0x41
    };

    ASSERT_TRUE(binson_parser_init(&p2, two_levels, sizeof(two_levels)));
    ASSERT_TRUE(p2.max_depth == 2);
    ASSERT_TRUE(binson_parser_verify(&p2));

    ASSERT_TRUE(binson_parser_reset(&p2));
    p2.max_depth = 1;
    ASSERT_FALSE(binson_parser_verify(&p2));
    ASSERT_TRUE(p2.error_flags == BINSON_ERROR_MAX_DEPTH);

}

/*======= Main function =====================================================*/

int main(void) {
    RUN_TEST(test_different_depths);
    PRINT_RESULT();
}

/*======= Local function implementations ====================================*/

