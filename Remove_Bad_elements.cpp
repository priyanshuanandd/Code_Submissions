#include <iostream>
#include <map>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    
    for (int test = 0; test < testcases; test++)
    {
        map<int,int> counter;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            counter[arr[i]]++;
        }
        int sizeofmap = sizeof(counter)/8;
        int com = -1;
        int total=0;
        for (auto &i : counter)
        {
            if (i.second > com )
            {
            
                com = i.second;
            }
            total += i.second;
            
        }
        total -= com;
        cout << total <<endl;
    }
    return 0;
}