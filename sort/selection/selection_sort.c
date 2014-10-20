#include <stdio.h>
#include "selection_sort.h"

#define swap(x, y)  do{x=x^y;y=x^y;x=x^y;}while(0)

int selection_sort(int *arr, int n)
{
    int i, j;
    int small;

    for (i = 0; i < n - 1; i++) {
        small = i;

        for (j = i + 1; j < n; j++) {
            if (arr[small] > arr[j]) {
                small = j;
            }
        }

        if (i != small) {
            swap(arr[i], arr[small]);
        }
//#define SORT_DEBUG
#ifdef SORT_DEBUG
        for (j = 0; j < 7; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
#endif
    }
}
