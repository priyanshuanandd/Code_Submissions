#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
 if (n == 1)
    {
        cout <<0;
    }
    else if (n == 2)
    {
        cout <<1;
    }
    int l = 1;
    int ltl = 0;
    int josaa;
    int cont = 0;
    for (int i = 3; i <= n+1; i++)
    {
        josaa = ltl + l;
        ltl = l;
        l = josaa;
    }
    cout << josaa;
    

}