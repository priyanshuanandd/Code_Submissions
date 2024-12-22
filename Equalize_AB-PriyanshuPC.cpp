#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        if (a > b | a < b)
        {
            int diff = abs(a - b);

            diff%2*x== 0 ? cout << "YES" << endl  :  cout << "NO"<<endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}