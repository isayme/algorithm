#include <stdio.h>
#include <string.h>

#include "kmp.h"

#define KMP_str(s, wanted) KMP(s, strlen(s), wanted, strlen(wanted))

int main()
{
    printf("%s\n", KMP_str("bbc abcdab abcdabcdabde", "abcdabd"));
    
    return 0;
}