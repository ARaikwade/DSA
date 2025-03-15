/******************************************************************************

selection sort: index sort, find out the right element for the given index.
first loop - find out the minimum number from arr[0] to arr[size]
second loop - find out the minimum no between arr[1] to arr[size]
.
.
.

*******************************************************************************/
#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int minIndex = i;
        
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main()
{
    int arr[6] = {3,6,5,2,1,4};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    print(arr, size);
    
    selectionSort(arr, size);
    
    print(arr, size);

    return 0;
}