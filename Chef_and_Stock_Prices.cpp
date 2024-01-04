#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        float stock, l, u, change;
        cin >> stock >> l >> u >> change;
        stock = stock + (stock * change) / 100;
        if (stock >= l && stock <= u)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}