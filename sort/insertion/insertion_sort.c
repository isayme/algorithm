#include <stdio.h>
#include "insertion_sort.h"

int insertion_sort(int *arr, int n)
{
    int i, j;
    int cur;

    if (NULL == arr || n <= 0) return -1;

    for (i = 1; i < n; i++) {
        cur = arr[i];
        j = i;
        while (j > 0 && arr[j-1] > cur) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = cur;

//#define SORT_DEBUG
#ifdef SORT_DEBUG
        for (j = 0; j < 7; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
#endif
    }

    return 0;
}
