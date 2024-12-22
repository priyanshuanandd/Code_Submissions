#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int n;
        cin >> n;
        int a[n];
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int mul = 1, neg = 0;

        for (int i = 0; i < n; i++)
        {
            mul *= a[i];
        }

        if (mul <0)
        {   
            cout << 1<<endl;
        }
        else{
            cout << 0<<endl;
        }
    }
    return 0;
}