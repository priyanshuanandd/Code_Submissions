#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
      float dist , time , bobdist ,bobtime;
      cin >> dist >> time >> bobdist >> bobtime;
      float alice = dist/time;
      float bob = bobdist/bobtime;
      if (alice > bob)
      {
        cout << "ALICE" << endl;
      }
      else if (bob > alice)
      {
        cout << "BOB" << endl;
      }
      else
      {
        cout << "EQUAL"<<endl;
      }
      
    }
    return 0;
}