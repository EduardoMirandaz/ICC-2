#include "quick_Sort.h"

void quick_Sort(int *arr, int size)
{
    quick(arr, 0, size - 1);
}

void quick(int *arr, int first, int last)
{
    if(first >= last)
    {
        return;
    }
    
    int middle = (first + last) / 2;
    int pivot = arr[middle];
    int i = first;
    int j = last;
    int temp;

    while(1)
    {
        while(arr[i] < pivot)
        {
            i++;
        }

        while(arr[j] > pivot)
        {
            j--;
        }

        if(i >= j)
        {
            break;
        }

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }

    quick(arr, first, j);
    quick(arr, j + 1, last);
}