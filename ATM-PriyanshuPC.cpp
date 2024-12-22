#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float req, balance;
    cin >> req >> balance;
    if ((int)req % 5 != 0 || req > balance)
    {
        cout << fixed << setprecision(2) << balance << endl;
    }
    else if(req < balance)
    {
        cout << fixed<<setprecision(2)<< (float)(balance - 0.50 - req)<< endl;
    }

    return 0;
}