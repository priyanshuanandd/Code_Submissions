#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    int f_element;
    for (int i = 0; i < n - 1; i++)
    {
        int posn = i, focus = arr[i], container = arr[i];
        int ii = i + 1;
        // iteration through array at the right of focus
        for (; ii <= n - 1; ii++)
        {
            if (arr[ii] < focus)
            {
                if (arr[ii] < container)
                {
                    container = arr[ii];
                    posn = ii;
                }
            }
        }
        if (container < focus)
        {
            swap(arr[i], arr[posn]);
        }
    }
}
int main()
{
    int arr[] = {3, 4, 5, 6, 2, 1};
    int n = sizeof(arr) / __SIZEOF_INT__;
    selection_sort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}