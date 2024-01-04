#include <iostream>
using namespace std;

int main()
{
    float count, a, b, c;
    cin>> count;
    for (size_t i = 0; i < count; i++)
    {
        cin>> a>> b>>c ;
        if (a + b + c == 180)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout<< "NO" << endl;
        }
    }

    return 0;
}