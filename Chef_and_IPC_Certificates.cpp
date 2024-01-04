#include <iostream>
using namespace std;

int main()
{ // n M K
    int numOfStudents, minTime, lecWatched, pass = 0;
    cin >> numOfStudents >> minTime >> lecWatched;
    int cont = lecWatched;
    while (numOfStudents--)
    {

        int lecWatched = cont;
        int watchTime = 0;
        int tatkal;
        while (lecWatched--)
        {
            cin >> tatkal;
            watchTime += tatkal;
        }
        int sawal;
        cin >> sawal;

        if (watchTime >= minTime and sawal <= 10)
        {
            pass++;
        }
    }
    cout << pass;
    return 0;
}