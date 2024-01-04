#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/4;
    int swap = 0;
    for (int i = 0; i < n/2; i++)
    {
        swap = arr[i];
        arr[i] =  arr[n-i-1];
        arr[n-1-i] = swap;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    
    
}