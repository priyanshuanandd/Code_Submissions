#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        int x;
        cin >> x;
        if (x < 100)
        {
            cout << "Easy"<<endl;
        }
        else if (x >=100 && x < 200)
        {
           cout << "Medium"<<endl;
        }
        
        else
        {
           cout << "Hard"<<endl;
        }
        
    }
    
    return 0;
}