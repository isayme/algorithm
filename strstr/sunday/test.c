#include <stdio.h>
#include <string.h>
#include "../../tcu/tcu.h"

#include "sunday.h"
#define str_str(s, wanted) sunday(s, strlen(s), wanted, strlen(wanted))

char *tc_001()
{
    unsigned char *rel = str_str("1234567890", "1234567890");
    TCU_EXPECT_STR_EQ(rel, "1234567890");
}

char *tc_002()
{
    unsigned char *rel = str_str("1234567890", "3456");
    TCU_EXPECT_STR_EQ(rel, "34567890");
}

char *tc_003()
{
    unsigned char *rel = str_str("1234567890", "7890");
    TCU_EXPECT_STR_EQ(rel, "7890");
}

char *tc_004()
{
    unsigned char *rel = str_str("1234567890", "8901");
    TCU_EXPECT_PTR_NULL(rel);
}

void ts()
{
    TCU_SUITE_ADD_TC(tc_001);
    TCU_SUITE_ADD_TC(tc_002);
    TCU_SUITE_ADD_TC(tc_003);
    TCU_SUITE_ADD_TC(tc_004);
}

int main()
{
    TCU_RUN_SUITE(ts);
    TCU_REPORT();
    
    return 0;
}