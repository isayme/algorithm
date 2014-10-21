#include <stdio.h>
#include <string.h>

#include "sunday.h"

#define sunday_str(s, wanted) sunday(s, strlen(s), wanted, strlen(wanted))

int main()
{
    printf("%s\n", sunday_str("bbc abcdab abcdabcdabde", "abcdabd"));
    
    return 0;
}