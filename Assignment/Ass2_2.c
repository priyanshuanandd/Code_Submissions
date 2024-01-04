#include <stdio.h>
// traverse an array
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < sizeof(arr)/4; i++)
    {
        printf("%d ", arr[i]);
    }
    
}