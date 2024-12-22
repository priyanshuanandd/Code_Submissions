#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
      int n , x;
      cin >> n >> x;
      if (x == 0 | x== n)
      {
        cout << 0<<endl;
      }
      else{
        int a = n-x;
        cout << min(a,x)<<endl;
      }
      
    }
    return 0;
}