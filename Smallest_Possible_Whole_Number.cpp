#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int number, sub;
        cin >> number >> sub;
        if (sub != 0)
        {
            if (number >= sub)
            {
                number = number % sub;
            }
        }

        cout << number << endl;
    }
    return 0;
}