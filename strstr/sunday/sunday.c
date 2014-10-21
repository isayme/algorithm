#include <stdio.h>
#include "sunday.h"

static int *sunday_bc(const unsigned char *wanted, int wlen, int *bc)
{
    int i;
    
    for (i = 0; i < 256; i++) {
        bc[i] = wlen;
    }
    
    for (i = 0; i < wlen; i++) {
        bc[wanted[i]] = wlen - i;
    }
    
    return bc;
}

unsigned char *sunday(const unsigned char *s, int slen, const unsigned char *wanted, int wlen)
{
    int i = 0;
    int bc[256];
    
    if (NULL == s || NULL == wanted || 0 >= wlen || slen < wlen) return NULL;
    if (s == wanted) return (unsigned char *)s;
    
    sunday_bc(wanted, wlen, bc);

    while (i <= slen - wlen) {
        if (0 == memcmp(s + i, wanted, wlen)) {
            return (unsigned char *)(s + i);
        }
        
        i += bc[s[i + wlen]];
    }
    
    return NULL;
}
