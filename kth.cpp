#include <iostream>
#include<algorithm>
using namespace std;
int kthSmallest(int A[], int k, int sizeOfArray)
{
    sort(A,A+sizeOfArray);
    int out = A[k-1];
    return out;


}
int main()
{
    int arr[] = {1, 2, 3, 4};
    cout<< arr;
}