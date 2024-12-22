#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
int testcases;
cin >> testcases;
for (int test = 0; test < testcases; test++)
{
    int arr[3];
    for (size_t i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+ 3);
    int ans = arr[1]+ arr[2];
    cout << ans << endl;
    
}
    return 0;
}