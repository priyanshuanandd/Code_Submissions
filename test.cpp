#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x =5;
    int * y = &x;
    int ** k = &y;
    cout << y << " " << &y   << endl;
    return 0;
}