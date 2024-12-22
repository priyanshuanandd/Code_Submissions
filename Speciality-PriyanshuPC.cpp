#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
      int x,y,z;
      cin >> x >> y >>z;
      if (x >= y and x >= z)
      {
        cout << "setter" << endl;
      }
      else if (y >= x and y >= z)
      {
        cout << "tester" << endl;
      }
      else if ( z >= x and z >= y)
      {
        cout << "editorialist" << endl;
      }
      
    }
    return 0;
}