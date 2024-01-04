#include <iostream>
using namespace std;
bool sort1(int arr[], int n)
{
    if (n == 1 or n == 0)
    {
        return true;
    }
    ////////ALEERTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT?????????????????/////////////////////////
    if (arr[0] < arr[1] and sort1(arr + 1, n - 1))
    {
        return true;
    }
    return false;
}



bool sort2(int arr[], int n,int i )
{
 //we will use an iterator in this one   
 
 if (i == n-1)
 {
    return true;
 }
 
 if (arr[i] < arr[i+1] and sort2(arr,n,i+1))
 {
    return true;
 }
  return false;
}


int main()
{
    int arr[]{1, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);
    int i = 0 ;
    cout << sort1(arr, n);
    cout << sort2(arr, n, i);
    return 0;
}