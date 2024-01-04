#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        for (int i = 1; n != 0; i++)
        {
            sum += n % 10;
            n /= 10;
        }

        cout << sum << endl;
    }
    return 0;
}