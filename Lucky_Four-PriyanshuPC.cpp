#include <iostream>
using namespace std;

int main()
{
    int count;
    cin>> count;
    for (int t = 0; t < count; t++)
    {
        int num,i=0;
        cin>> num;
        while (num!=0)
        {
            int remainder = num%10;
            if (remainder == 4)
            {
                i= i+1;
            }

            num/=10;
 
        }
                   cout<< i<< endl;
    }
    
    return 0;
}