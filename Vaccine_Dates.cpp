#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        int d, l, u;
        cin >> d >> l >> u;
        if (d >= l &&  d <= u)
        {
            cout << "Take second dose now"<< endl;
        }
        else if (d > u)
        {
            cout << "Too Late"<< endl;
        }
        else
        {
            cout << "Too Early"<< endl;
        }
        
    }

    return 0;
}