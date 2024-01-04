#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        float a, b, x, y;
        cin >> a >> b >> x >> y;

        if (a/x < b/y)
        {
            cout << "Chef" << endl;
        }
        else if (a/x > b/y)
        {
            cout << "Chefina" << endl;
        }
        else
        {
            cout << "Both" << endl;
        }
    }
    return 0;
}