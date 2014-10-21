#include <stdio.h>
#include "bm.h"

#define MAX(a, b) (((a)>(b))?(a):(b))

static int preBmBc(const unsigned char *wanted, int wlen, int bmBc[])
{
    int i;
    
    if (NULL == wanted || 0 >= wlen || NULL == bmBc) return -1;
    
    for (i = 0; i < BM_ASIZE; i++) {
#if BM_VERSION == 1
        bmBc[i] = -1;
#else
        bmBc[i] = wlen;
#endif              
    }

    for (i = 0; i < wlen - 1; i++) {
#if BM_VERSION == 1
        bmBc[wanted[i]] = i ;
#else
        bmBc[wanted[i]] = wlen - i - 1;
#endif      
    }
      
    return 0;
}

static int suffixes(const unsigned char *wanted, int wlen, int *suffix)
{
    int f, g, i;

    if (NULL == wanted || 0 >= wlen || NULL == suffix) return -1;
    
    suffix[wlen-1] = wlen;
   
    g = wlen - 1;
    for (i = wlen - 2; i >= 0; i--) {
        if (i > g && suffix[wlen-1+i-f] < i - g) {
            suffix[i] = suffix[wlen-1+i-f];
        } else {
            if (i < g) {
                g = i;
            }
            
            f = i;
            while (g >= 0 && wanted[g] == wanted[wlen-1+g-f]) {
                g--;
            }
            suffix[i] = f - g;
        }
    }
   
    return 0;
   
    /* ablove code more efficient, general below
    suffix[wlen-1] = wlen;
    for (i = wlen-2; i >= 0; i--){
        q = i;
        while (q >= 0 && P[q] == P[wlen - 1 - i + q])
            --q;
        suffix[i]=i-q;
    }*/
}
 
static int preBmGs(const unsigned char *wanted, int wlen, int bmGs[])
{
    int i, j, suffix[BM_XSIZE];

    if (NULL == wanted || 0 >= wlen || NULL == bmGs) return -1;
    
    suffixes(wanted, wlen, suffix);
    
    for (i = 0; i < wlen; i++) {
        bmGs[i] = wlen;
    }

    for (j = 0, i = wlen - 1; i >= 0; i--)
    {
        if (suffix[i] == i + 1) {
            for (; j < wlen - 1 - i; j++) {
                if (bmGs[j] == wlen) {
                    bmGs[j] = wlen - 1 - i;
                }
            }
        }
    }

    for (i = 0; i <= wlen - 2; i++) {
        bmGs[wlen - 1 - suffix[i]] = wlen - 1 - i;
    }

    return 0;
}
 
 
unsigned char *BM(const unsigned char *s, int slen, const unsigned char *wanted, int wlen)
{
    int i;
    int j = 0;
    int len = slen - wlen;
    int bmGs[BM_XSIZE];
    int bmBc[BM_ASIZE];
    
    if (NULL == wanted || 0 > wlen || NULL == s || slen < wlen) return NULL;

    if (-1 == preBmGs(wanted, wlen, bmGs) || -1 == preBmBc(wanted, wlen, bmBc)) return NULL;
    
    while (j <= len) {
        for (i = wlen - 1; i >= 0 && wanted[i] == s[i+j]; i--);
        if (i < 0) {
            return (unsigned char *)(s + j);
        } else {
#if BM_VERSION == 1
            j += MAX(bmGs[i], i - bmBc[s[i+j]]);
#else
            j += MAX(bmGs[i], bmBc[s[i+j]] - wlen + 1 + i);
#endif
        }
    }
    
    return NULL;
}
