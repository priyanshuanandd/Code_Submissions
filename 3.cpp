#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (size_t space = 1; space <= (n - i); space++)
        {
            cout << " ";
        }
        for (size_t star = 1; star <= (2 * i - 1); star++)
        {
            cout << "*";
        }
        cout<< endl;
    }

    return 0;
}
