#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
      int n ;
      cin >> n;
      int ans = n/2 +1;
      cout << ans<< endl;
    }
    return 0;
}