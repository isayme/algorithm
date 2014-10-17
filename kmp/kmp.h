#ifndef _KMP_H
#define _KMP_H

int *KMP_pmt(unsigned char *wanted, int wlen);
unsigned char *KMP(unsigned char *s, int slen, unsigned char *wanted, int wlen);

#endif