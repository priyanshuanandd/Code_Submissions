#include <iostream>
using namespace std;

int main()
{
    int n, righty;
    cin >> n;
    char ch;
    while (n>0)
    {

        for (righty = 0; righty < n; righty++)
        {
            ch = 'A' + righty;
            cout << ch;
        }
        for (int lefty = 0; lefty < n; lefty++)
        {
            cout << (char)(ch - lefty);
        }
        cout<< endl;
        n--;
    }
    return 0;
}