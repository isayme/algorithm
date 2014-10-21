#include <stdio.h>
#include <string.h>

#include "bm.h"

#define BM_str(s, wanted) BM(s, strlen(s), wanted, strlen(wanted))

int main()
{
    // pattern length must <= 256
    printf("%s\n", BM_str("ANPAXMANPANMANMANPANMAN", "ANPANMAN"));

    return 0;
}