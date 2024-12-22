#include <bits/stdc++.h>
using namespace std;

char largestFrequencyCharacter(char c[], int size)
{
    sort(c,c+size);
    char MaxChar;
    int freq = -1;
    int cmpChar = c[0];
    for (int indx = 0; indx < size;)
    {
        int currentcount = 0;
        while (c[indx] == cmpChar)
        {
            currentcount++;
            indx++;
        }
        if (currentcount > freq)
        {
            freq = currentcount;
            MaxChar = c[indx -1];
        }
        cmpChar = c[indx];
    }
   return MaxChar;
    
}
int main()
{
    char c[] = "abbcdeeeee";
    int size = strlen(c);

    largestFrequencyCharacter(c, size);
}