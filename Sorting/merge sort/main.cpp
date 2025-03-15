/******************************************************************************
merge sort:
Steps of Merge Sort:
Divide the Array:
Split the array into two halves until each subarray contains only one element. A single element is considered sorted by itself.

Merge the Arrays:
Gradually combine (merge) the smaller sorted arrays to form a larger sorted array. During the merging process, elements are placed in the correct order.

Repeat Until Sorted:
Keep merging until the entire array is sorted.

*******************************************************************************/
#include <iostream>

using namespace std;

void print(int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void merge(int array[], int left, int mid, int right)
{
    //divide array into two parts
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    int leftArray[leftSize];
    int rightArray[rightSize];
    for(int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }
    for(int i = 0; i < rightSize; i++)
    {
        rightArray[i] = array[mid+i+1];
    }
    
    //Merge two arrays into one
    int leftIndex = 0;
    int rightIndex = 0;
    int index = left;
    while(leftIndex < leftSize && rightIndex < rightSize)
    {
        if(leftArray[leftIndex] <= rightArray[rightIndex])
            array[index++] = leftArray[leftIndex++];
        else
            array[index++] = rightArray[rightIndex++];
    }
    
    while(leftIndex < leftSize)
        array[index++] = leftArray[leftIndex++];
        
    while(rightIndex < rightSize)
        array[index++] = rightArray[rightIndex++];
    
}

void mergeSort(int array[], int left, int right)
{
    if(left >= right)
        return;
    
    int mid = left + (right-left) / 2;
        
    mergeSort(array, left, mid);
    mergeSort(array, mid+1, right);
    
    merge(array, left, mid, right);
}

int main()
{
    int array[] = {12,11,13,10,5,7,6};
    
    int size = sizeof(array)/sizeof(array[0]);
    
    print(array, size);
    
    mergeSort(array, 0, size-1);
    
    print(array, size);

    return 0;
}