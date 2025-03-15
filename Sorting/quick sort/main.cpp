/******************************************************************************

quick sort:

Steps of Quick Sort:
Pick a Pivot: Choose an element from the array as the "pivot." The pivot is used to divide the array into smaller parts. Commonly, the first, last, or middle element is chosen, but it can be any element.

Partition the Array:

Arrange the array such that all elements smaller than the pivot are moved to its left, and all elements larger than the pivot are moved to its right.

The pivot ends up in its correct sorted position in the array.

Recursively Sort:

Apply the same steps (pick a pivot and partition) to the left and right subarrays created from the partitioning process.

Repeat Until Sorted:

The recursion stops when the subarrays are empty or have just one element, which means they're already sorted.

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

void swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex)
{
    int swapIndex = pivotIndex;
    
    for(int i = pivotIndex+1; i <= endIndex; ++i)
    {
        if(array[i] < array[pivotIndex])
        {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, swapIndex, pivotIndex);
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex)
{
    if(leftIndex >= rightIndex)
        return;
        
    int pivotIndex = pivot(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, pivotIndex-1);
    quickSort(array, pivotIndex+1, rightIndex);
}

int main()
{
    int array[] = {4,6,1,7,3,2,5};
    
    int size = sizeof(array)/sizeof(array[0]);
    
    print(array, size);
    
    quickSort(array, 0, size-1);
    
    print(array, size);

    return 0;
}