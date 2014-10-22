#ifndef _TCU_H
#define _TCU_H

static int tcu_passed = 0;
static int tcu_failed = 0;

#define TCU_PRINTF(fmt, ...)  do {                              \
    fprintf(stderr, fmt, ##__VA_ARGS__);                        \
} while (0)

#define TCU_SUITE_ADD_TC(tc) do {                               \
    char *rel = tc();                                           \
    if (NULL == rel) {                                          \
        tcu_passed++;                                           \
        TCU_PRINTF("TC [%s] \033[32mpassed\033[0m\n", #tc);     \
    } else {                                                    \
        tcu_failed++;                                           \
        TCU_PRINTF("TC [%s] \033[31mfailed, "                   \
                "%s\033[0m\n", #tc, rel);                       \
    }                                                           \
} while(0)

#define TCU_EXPECT_STR_EQ(expect, real) do {                    \
    return 0 == strcmp(expect, real) ? NULL :                   \
                "expect [" #expect "], but got [" #real "]";    \
} while(0);

#define TCU_EXPECT_PTR_NULL(real) do {                          \
    return NULL == real ? NULL : "expect NULL pointer";         \
} while(0);

#define TCU_EXPECT_INT_EQ(expect, real) do {                    \
    return expect == real ? NULL :                              \
                "expect [" #expect "], but got [" #real "]";    \
} while(0);

#define TCU_RUN_SUITE(ts) do {                                  \
    ts();                                                       \
} while(0)

#define TCU_RESET() do {                                        \
    tcu_passed = 0;                                             \
    tcu_failed = 0;                                             \
} while(0)

#define TCU_REPORT() do {                                       \
    TCU_PRINTF("\n #\n"); \
    TCU_PRINTF(" # Report: \033[36mTotal TC [%d]\033[0m, "      \
            "\033[32mPassed [%d]\033[0m, "                      \
            "\033[31mFailed [%d]\033[0m.\n",                    \
            tcu_passed + tcu_failed, tcu_passed, tcu_failed);   \
    TCU_PRINTF(" #\n\n"); \
} while(0)

#endif