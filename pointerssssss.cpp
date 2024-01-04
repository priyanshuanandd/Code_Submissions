#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v = 5;
    int *v2 = &v;
    cout << v2 <<" " <<  *v2;
    // output : 0x61ff08 5
    return 0;
}