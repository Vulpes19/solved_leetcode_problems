#include <iostream>

using namespace std;

/*
    Mark first element as sorted 
    for each unsorted element X
        extract element X
        for last sorted Index down to 0
            if current element is bigger than X
            Move sorted element to the right by 1
        Break the loop and insert X here
*/

void    insertionSort( int *arr, int len )
{
    for ( size_t i = 1; i < len; i++ )
    {
        int key = arr[i];
        int j = i - 1;
        while ( j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for ( int i = 0; i < len; i++ )
        cout << arr[i] << endl;
}

int main( void )
{
    int arr[6] = {4, 2, 1, 9, 7, 5};
    insertionSort(arr, 6); 
    return (0);
}
