#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
       double ini , req , dec ,dis ,com;
        double kk = 0;
        cin >> ini >> req>> dec >> dis;
        com  = ini*ini - 2*dec*dis;
        if (com > 0 )
        {
             kk = sqrt((float)com);
        }
        if (kk <= req)
        {
          cout << "Yes" << req<< endl;  
        }
        else
        {
         cout << "No" <<req << endl;
        }
        
    }
    return 0;
}