#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        int a , b , a1 ,b1 ,a2 ,b2;
        cin >> a >> b >> a1 >> b1 >> a2 >> b2 ;
        if ((a == a1 && b == b1 )|(a == b1 && b == a1) )
        {
            cout << 1;
        }
        else if ((a == a2 && b == b2 )|(a == b2 && b == a2))
        {
           cout << 2;
        }
        else
        {
            cout << 0;
        }
        cout << endl; 
    }
    
    return 0;
}