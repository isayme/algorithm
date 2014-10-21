#include <stdio.h>
#include "quick_sort.h"

#define swap(x, y)  do{x=x^y;y=x^y;x=x^y;}while(0)

int quick_sort(int *arr, int left, int right)
{
    int pivot;
    int i, j;
    
    if (NULL == arr || left >= right) return -1;
    
    pivot = arr[left];
    i = left;
    j = right + 1;
    
    while (i < j) {
        do { j--; } while (arr[j] > pivot);
        do { i++; } while (i <= j && arr[i] <= pivot);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    
    if (left < j) {
        swap(arr[left], arr[j]);
        quick_sort(arr, left, j - 1);
    }
    quick_sort(arr, j + 1, right);
    
    return 0;
}
