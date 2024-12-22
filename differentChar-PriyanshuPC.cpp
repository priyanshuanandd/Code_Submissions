#include <bits/stdc++.h>
using namespace std;

int countOfDifferentCharacters(char c[], int size)
{
    map<char, int> mapp;
    for (int i = 0; i < size; i++)
    {
        mapp[c[i]]++;
    }
    int count = 0;
    for (auto &i : mapp)
    {
        count++;
    }

    return count;
}
int main()
{
    char c[] = "jk";
    int size = strlen(c);
    cout << countOfDifferentCharacters(c, size);
}