#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
      int target , run;
      cin >> target >> run;
      cout << target -run <<endl;
    }
    return 0;
}