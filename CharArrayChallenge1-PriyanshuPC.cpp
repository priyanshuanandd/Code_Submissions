#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int k ;
    char sentences[10000];
    int N = 0;
    cin >> k;
    cin.get();
    while (k--)
    {
        int stringlength;
        char current[1000];

        cin.getline(current,1000);
        int n = strlen(current);
        if (n > N)
        {
           //update 2 things
           N=n;
           strcpy(sentences,current);
        }
        

    }
    cout << sentences << endl;
    
    return 0;
}




//n is the no. of lines followed by n string cout the string which is the longest among them all

