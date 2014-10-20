#ifndef _BM_H
#define _BM_H


#define BM_XSIZE 256
#define BM_ASIZE 256

#define BM_VERSION 1

unsigned char *BM(const unsigned char *s, int slen, const unsigned char *wanted, int wlen);

#endif