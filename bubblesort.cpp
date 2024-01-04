#include <iostream>
using namespace std;

void bubblesort(int arr[],int n){
    //for getting the no. of iterations
    for (int tt = 0; tt < n-1; tt++)
    {
        //element number
        for (int  i = 0; i < n -1 -tt; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
            
        }
        
    }
    
}
int main()
{  int arr[] = {3, 4, 5, 6, 2, 1};
    int n = sizeof(arr) / __SIZEOF_INT__;
    bubblesort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}