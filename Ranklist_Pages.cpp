#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
     //each page 25 aadmi
      int rank;
      cin >> rank;
      int page = rank/25 +1;
      if (rank%25 == 0)
      {
        page = rank/25;
      }
      
      cout << page <<endl;
    }
    return 0;
}