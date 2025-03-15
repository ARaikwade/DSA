/******************************************************************************

Insertion sort

*******************************************************************************/
#include <iostream>

using namespace std;

void print(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int size)
{
    for(int i = 1; i < size; ++i)
    {
        int temp = arr[i];
        int j = i - 1;
        
        while(j >= 0 && temp < arr[j])
        {
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main()
{
    int arr[6] = {3, 4, 6, 1, 2, 5};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    print(arr, size);
    
    insertionSort(arr, size);
    
    print(arr, size);

    return 0;
}