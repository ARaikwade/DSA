/******************************************************************************

Bubble sort: find the max item and place it at the end

*******************************************************************************/
#include <iostream>

using namespace std;

void print(const int arr[], const int &size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], const int &size)
{
    for(int i = size; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    print(arr, 6);
}

int main()
{
    int arr[6] = {3, 4, 6, 1, 2, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    print(arr, size);
    
    bubbleSort(arr, size);
    print(arr, size);
    return 0;
}