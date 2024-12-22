#include <iostream>
using namespace std;

int main()
{   int count;
    cin>> count;
    for (size_t i = 0; i < count; i++)
    {
        int n , k;
        cin >> n >> k;
        if (n >= (k*(k+1))/2)
        {
            cout<< "YES"<<endl;
        }
        else{
            cout<< "NO" << endl;
        }
    }
    
    return 0;
}