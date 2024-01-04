#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int no, fruits, veg, fishes, dishes = 0;
        cin >> no >> fruits >> veg >> fishes;
        do
        {
            if (fruits > 0 && veg > 0)
            {
                dishes++;
                fruits--;
                veg--;
            }
            if (veg > 0 && fishes > 0)
            {
                dishes++;
                veg--;
                fishes--;
            }
        } while (veg > 0 && fishes > 0 | fruits > 0 && veg > 0);
        if (dishes >= no)
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