#include <iostream>
using namespace std;

int main()
{
    int testcases, neg = 0, zero = 0;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int length;
        cin >> length;
        int arr[length];

        for (int i = 0; i < length; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < length; i++)
        {
            if (arr[i] < 0)
            {
                neg++;
            }
            else if (arr[i] == 0)
            {
                zero++;
            }

        }

        if (zero > 0)
        {
            cout << 0 << endl;
        }
        else
        {
            if (neg % 2 == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }
    return 0;
    

}
