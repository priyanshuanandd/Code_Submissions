#include <bits/stdc++.h>
using namespace std;

int isSorted(char c[], int size)
{
    int prevchar = c[0];
    for (int i = 0; i < size; i++)
    {
        int currentchar = c[i];
        if (i > 1)
        {
            prevchar = c[i-1];
        }
        
        if (currentchar < prevchar)
        {
            return -1;
        }
    }
    return 0;
}
int main()
{
    char c[] = "aabbbccddd";
    int size = strlen(c);
    cout <<  isSorted(c, size);
}