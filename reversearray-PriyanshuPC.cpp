#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n],first=0 ,last =0;
    
    for (size_t i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    for (int t = 0; t*t < n; t++)
    {
        first = arr[t];
        last  = arr[n-1-t];
        //cout << first << " " << last<< endl;
        arr[n-1 - t]= first;
        arr[t] = last;
        
    }
    
    for (size_t i = 0; i < n; i++)
    {
        cout<< arr[i]<< " ; ";
    }
    
    
    return 0;
}