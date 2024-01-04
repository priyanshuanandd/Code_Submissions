#include <bits/stdc++.h>
using namespace std;
void watchVideo(int *viewsPtr)
{
    // watch video should increment view count by 1
    *viewsPtr = *viewsPtr + 1;
}
int main()
{
    int views = 100;
    int *p = &views;
    int **pp = &p;
    cout << p  << endl;
    cout << *p  << endl;
    cout << &p  << endl;
    cout << pp  << endl;
    cout << *pp  << endl;
    
    return 0;
}