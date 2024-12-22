#include <iostream>
#include <map>
using namespace std;
typedef long long int ll;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)

    {
        int n, condition, bheek;
        cin >> n >> condition >> bheek;
        int arr[n];
        int onecount = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                onecount++;
            }
        }
        // for bhik wale points
        int bhikcount = 0;
        for (int i = 0; i < condition; i++)
        {
            if (arr[i] == 0)
            {
                bhikcount++;
            }
        }
        if (bhikcount == 0 and onecount != n)
        {
            cout << bheek << endl;
        }
        else if(bhikcount !=0 and onecount != n)
        {
            cout << 0 << endl;
        }
        if (onecount == n)
        {
            cout << 100 << endl;
        }
    }
    return 0;
}