#include <bits/stdc++.h>
using namespace std;

pair<int, int> largestAndSmallest(int A[], int sizeOfArray)
{
    sort(A,A+sizeOfArray);
    int lar = A[sizeOfArray-1];
    int smal = A[0];
    return pair<int, int>(lar, smal);
    
}
int main()
{

     int arr[] = {1,2,3,4};
    
    int n = sizeof(arr)/sizeof(int);
    cout << largestAndSmallest(arr,n);
    return 0;
}