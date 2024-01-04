#include <iostream>
using namespace std;

int main()
{
    char letterone = 'A';
    int n;
    cin >> n;
    int count = 0;
    while (n--)
    {
        
        count++;

        // increase
        for (int i = 0; i < count; i++)
        {
            cout << letterone;
            letterone++;
        }
        //decrease
        letterone--;
        while ((int)letterone!= 64 )
        {
            cout << letterone;
            letterone--;
        }
        cout << endl;
        letterone = 'A';
    }

    return 0;
}