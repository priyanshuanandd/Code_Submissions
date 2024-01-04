#include <iostream>
#include<string>
using namespace std;

int main()
{
    string para = "the quick brown fox jumps over the lazy dog";
    string search;
    getline(cin,search);
    int posn = 0;
    int hoho = 0;
    while (hoho!= -1)
    {   
        hoho = para.find(search,posn);
        if (hoho == -1)
        {
            break;
        }
        
        cout << "word is at " <<  hoho << endl;
        posn+= hoho +1;
    }
    

    return 0;
}