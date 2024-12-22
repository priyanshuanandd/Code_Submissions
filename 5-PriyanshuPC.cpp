#include <iostream>
using namespace std;

int main()
{
    int n;
    int right = 65;
    cin >> n;
           for (size_t i = 0; i < n; i++)
        {

            right += i;
            cout << (char)right;
        }
        for (size_t k = 0; k < n; k++)
        {
            right -= k;
            cout << (char)right;
        }
        cout << endl;
    }
    return 0;
}