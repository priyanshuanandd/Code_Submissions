#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
      int n;
      cin >> n;
      if (n < 7)
      {
        cout << "YES"<<endl;
      }
      else
      {
        cout << "NO"<<endl;
      }
      
    }
    return 0;
}