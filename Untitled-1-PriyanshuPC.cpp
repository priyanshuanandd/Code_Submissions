#include <iostream>
using namespace std;

int main()
{
    char sign;
    int a,b;
    cin>> a>>sign>>b;
    switch((char)sign){
        
        case '+': cout<< a + b; break;
        case '*' : cout<< a * b; break;
        case '-' : cout<< a - b; break;
        case '/' : cout<< a / b; break;

    }

    return 0;
}