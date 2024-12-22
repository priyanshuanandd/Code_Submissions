#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int tomx, tomy, jerx, jery, K;
        cin >> tomx >> tomy >> jerx >> jery >> K;
        int ki = abs(tomx - jerx);
        int ri = abs(tomy - jery);
        int dis = ri + ki;
        if (dis == K)
        {
            cout << "YES" << endl;
        }
        else if (dis < K)
        {
            int k = K -dis;
            k%2 == 0 ? cout<< "YES" : cout <<"NO";
            cout<<endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}