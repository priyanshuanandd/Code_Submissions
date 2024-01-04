#include <iostream>
#include <algorithm>
using namespace std;
int binarysearch(int arr[], int n, int r)
{
    int s = 0;
    int e = n - 1;
    int mid = (e - s) / 2;
    while (s <= e)
    {
        int mid = (e - s) / 2;
        if (arr[mid] >  r)
        {
            e = mid-1;
        }
        else if (arr[mid] <  r)
        {
            s = mid+1;
        }
        else
        {
           return mid;
        }
    }
    return -1;
}
int main()
{
    int n, r;
    cin >> n >> r;
    int arr[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    cout << binarysearch(arr, n, r);
    return 0;
}
