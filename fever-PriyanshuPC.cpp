#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        int t;
        cin >> t;
        if (t>98)
        {
            cout<< "YES"<<endl;         
        }
        else{
            cout<< "NO"<< endl;
        }
    }

    return 0;
}