#include <iostream>
using namespace std;

int main()
{
    int count;
    cin>> count;
    for (size_t i = 0; i < count; i++)
    {
        int num,remainder,first=0,last=0;
        cin>> num;
        for (size_t n= 0;num!=0 ; n++)
        {
            remainder = num%10;
            if (n==0)
            {
                first = remainder;
            }
                last = remainder;
            num /= 10;
        }
        cout<< first + last << endl;
        
    }
    
    return 0;
}