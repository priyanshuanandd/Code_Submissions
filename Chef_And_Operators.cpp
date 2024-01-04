#include <iostream>
using namespace std;

int main()
{
    int i, a, b;
    cin >> i;
    for (int k = 0; k < i; k++)
    {
        cin >> a >> b;
        if (a > b)
        {
            cout << ">"<< endl;
        }
        if (a < b)
        {
            cout << "<"<< endl;
        }
        if (a == b)
        {
            cout << "="<< endl;
        }
    }
    return 0;
}