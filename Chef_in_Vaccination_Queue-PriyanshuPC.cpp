#include <iostream>
using namespace std;

int main()
{
  int testcases;
  cin >> testcases;
  for (int test = 0; test < testcases; test++)
  {
    int people, chef_posn, timec, timee;
    cin >> people >> chef_posn >> timec >> timee;
    int time = 0;
    int peoplearray[people];
    for (size_t i = 0; i < people; i++)
    {
      cin >> peoplearray[i];
    }

    for (int i = 0; i <= chef_posn - 1; i++)
    {
      if (peoplearray[i] == 0)
      {
        time += timec;
      }
      else
      {
        time += timee;
      }
    }
    cout << time << endl;
  }
  return 0;
}