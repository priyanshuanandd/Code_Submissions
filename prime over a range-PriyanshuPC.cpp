#include <iostream>
using namespace std;

bool primeCheck(int a)
{
    for (size_t i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int print(int a, int b)
{
    for (size_t i = a; i <= b; i++)
    {
        cout << i << " is " << (primeCheck(i) ? "Prime" : "Non-Prime");
        cout << endl;
    }
    return 0;
}
void printprime(int a, int b)
{
    for (size_t i = a; i <= b; i++)
    {
       if (primeCheck(i))
       {
        cout<< i<< endl;
       }
        
    }
    
}
int main()
{
    int a, b;
    cin >> a >> b;
    printprime(a,b);
   
   //print(a, b);
    return 0;
}
