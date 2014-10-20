#ifndef _KMP_H
#define _KMP_H

int *KMP_pmt(const unsigned char *wanted, int wlen);
unsigned char *KMP(const unsigned char *s, int slen, const unsigned char *wanted, int wlen);

#endif