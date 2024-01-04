#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        // 1 pizza 4slice
        //  n friends
        // 1 friend x slices
        int n, x;
        cin >> n >> x;
        int piz = (n * x) / 4;
        if ((n * x) % 4 == 0)
        {
            cout << piz << endl;
        }
        else
        {
            cout << piz + 1 << endl;
        }
    }
    return 0;
}