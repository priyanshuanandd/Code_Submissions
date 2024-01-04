#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 0 | n == 1)
    {
        return n;
    }

    int answer = fib(n - 1) + fib(n - 2);
    return answer;
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}