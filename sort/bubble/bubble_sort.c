#include <stdio.h>
#include "bubble_sort.h"

#define swap(x, y)  do{x=x^y;y=x^y;x=x^y;}while(0)

int bubble_sort(int *arr, int n)
{
    int i, j;

    if (NULL == arr || n <= 0) return -1;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }

//#define SORT_DEBUG
#ifdef SORT_DEBUG
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
#endif
    }

    return 0;
}
