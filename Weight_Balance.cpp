#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int w1 ,w2,x1,x2,m;
        cin >> w1>> w2>> x1>> x2>> m;
        int maxi = x2*m;
        int min = x1*m;
        int diff = w2 - w1;
        if (maxi>= diff && diff >= min)
        {
            cout << 1<< endl;
        }
        else{
            cout << 0 <<endl;
        }
      
    }
    return 0;
}