#include <iostream>
using namespace std;

int main()
{
    int i = 1, a, b, c;
    cin >> c;
    while (i <= c)
    {
        cin >> a >> b;
        cout << a % b << endl;
        i++;
    }

    return 0;
}