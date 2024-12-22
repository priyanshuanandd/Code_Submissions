#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int *arr, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}

int findMissingNumber(int A[], int sizeOfArray)
{

    sort(A, A + sizeOfArray);
    int out;
    for (int i = 0; i <= sizeOfArray; i++)
    {
        /* code */
        if (A[i] != i + 1)
        {
            out =  i+ 1;
            break;
        }
    }
    return out;
}

int main()
{
    int arr[] = {};
    
    int n = sizeof(arr)/sizeof(int);
    cout<< findMissingNumber(arr,n);
    return 0;
}