#include <iostream>
using namespace std;

int main()
{
    int count;
    cin>> count;
    int arr[count] ;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = i; j < count; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k]<< " " ;
            }
            cout<< endl;
        }
        cout << endl;
    }

    return 0;
}