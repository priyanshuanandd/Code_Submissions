#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
      int current,sal,charges,months;
      cin >> current >> sal >> charges >> months;
      while (months--)
      {
        current += (sal -charges);
      }
      cout << current <<endl;
      
    }
    return 0;
}