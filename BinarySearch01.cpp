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

int binary_search(int arr[], int n, int key)
{
    
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int key;
    cin >> key;
    int arr[] = {1, 5, 6, 7, 888, 3, 55, 6, 7, 9, 0, 1, 2, 45, 6, 5, 4, 3, 3};
    int n = sizeof(arr) / __SIZEOF_INT__;
    sort(arr, arr + n);
    printArray(arr,n) ;
    cout << endl<< endl;
    int baba = binary_search(arr,n,key);

    if (baba == -1)
    {
        cout << key << " isn't in the array";
    }
    else
    {
        cout << key << " is at " << baba<< " in the array";
    }
    
    return 0;
}