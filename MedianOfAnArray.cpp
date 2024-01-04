#include <iostream>
using namespace std;
int calculateMedian(int A[], int sizeOfArray) {
    bool od  = (sizeOfArray%2 == 0 );
    int k;
    od ? (k= sizeOfArray/2) : (k = sizeOfArray/2 +1);
    cout << A[k-1];
}

int main()
{
     int arr[] = {1,2,3,4};
    
    int n = sizeof(arr)/sizeof(int);
    calculateMedian(arr,n);
    return 0;
}