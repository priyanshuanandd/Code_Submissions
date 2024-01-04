#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (size_t o = 0; o < count; o++)
    {
        int number, c = 0, i;
        cin >> number;
        for (i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                c++;
            }
        }
        if (c > 0)
        {
            cout << "NON-PRIME"<<endl;
        }
        else
        {
            cout << "PRIME"<< endl;
        }
    }
    return 0;
}