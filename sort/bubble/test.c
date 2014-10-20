#include <stdio.h>
#include "bubble_sort.h"

int main()
{
    int i;
    int arr[7] = {48, 36, 68, 72, 12, 48, 02};

    bubble_sort(arr, 7);

    for (i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}