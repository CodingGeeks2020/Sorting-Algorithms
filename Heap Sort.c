#include <stdio.h>
#include <stdlib.h>
#define PRINT(array, length)         \
    for (int i = 0; i < length; i++) \
        printf("%d\t", array[i]);

typedef struct MaxHeap
{
    int size;
    int *array;
} MaxHeap;

void swap(int *l, int *i)
{
    int temp = *l;
    *l = *i;
    *i = temp;
}

//Heapify
void heapify(MaxHeap *maxHeap, int idx)
{
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
    {
        largest = left;
    }
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
    {
        largest = right;
    }

    if(largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        heapify(maxHeap, largest);
    }
}


//Build heap
MaxHeap *BuildHeap(int *array, int size)
{
    int i;
    MaxHeap *maxHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
    maxHeap->array = array;
    maxHeap->size = size;
    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
    {
        heapify(maxHeap, i);
    }

    return maxHeap;
}

//Heapsort
void heapSort(int *array, int size)
{
    MaxHeap *maxHeap = BuildHeap(array, size);
    while(maxHeap->size >1)
    {
        swap(&maxHeap->array[0],&maxHeap->array[maxHeap->size-1]);
        --maxHeap->size;
        heapify(maxHeap,0);
    }
}

/********UNIT TEST*********/
int main()
{
    //int arr[] = {12, 11, 13, 5, 6, 7};
    int arr[] = {-2, 0, 9, 9, 16, 17, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    printf("\nSORTED ARRAY IS \n");
    //printArray(arr, size);
    PRINT(arr, size);
    return 0;
}