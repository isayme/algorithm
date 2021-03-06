#include <stdio.h>
#include <stdlib.h>

#include "kmp.h"

int *KMP_pmt(const unsigned char *wanted, int wlen)
{
    int *pmt = NULL;
    int i;
    int k;

    if (NULL == wanted || 0 >= wlen) return NULL;

    pmt = malloc(sizeof(int) * wlen);
    if (NULL == pmt) return NULL;

    for (i = 1, k = 0, pmt[0] = 0; i < wlen; i++) {
        while (k > 0 && wanted[i] != wanted[k]) {
            k = pmt[k-1];
        }

        if (wanted[i] == wanted[k]) {
            k++;
        }
        pmt[i] = k;
    }

    return pmt;
}

unsigned char *KMP(const unsigned char *s, int slen, const unsigned char *wanted, int wlen)
{
    int *pmt = NULL;
    int i = 0;
    int j = 0;
    
    if (NULL == s || NULL == wanted || 0 >= wlen || slen < wlen) return NULL;
    if (s == wanted) return (unsigned char *)s;

    pmt = KMP_pmt(wanted, wlen);
    if (NULL == pmt) return NULL;

    while (i < slen && j < wlen) {
        if (s[i] == wanted[j]) {
            i++;
            j++;
        } else {
            if (0 == j) {
                i++;
            } else {
                j = pmt[j-1];
            }
        }
    }

    free(pmt);

    return j == wlen ? (unsigned char *)(s + i - wlen) : NULL;
}
