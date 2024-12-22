#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        //logic : go through the array finding i which is the iterator and then find the posn of the number and store the number with the posn having the largest value
        int storage = -1;
        for ( int j= 1; j < 8; j++)
        {
            for ( int k = 0; k < n; k++)
            {
                if (arr[k] == j and k > storage)
                {
                    storage = k;
                }
                
            }
            
        }
        cout << storage +1<< endl;
        
    }
    return 0;
}