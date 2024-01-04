#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        int repair, buy;
        cin >> repair >> buy;
        if (repair < buy)
        {
            cout << "REPAIR" << endl;
        }
        else if (buy < repair)
        {
            cout << "NEW PHONE" << endl;
        }
        else if (buy == repair)
        {
            cout << "ANY" << endl;
        }
    }

    return 0;
}