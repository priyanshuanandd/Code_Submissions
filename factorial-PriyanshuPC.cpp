#include <iostream>
using namespace std;

int factorial(int num)
{
    int facto = 1;

    for (size_t i = 1; i <= num; i++)
    {
        facto *= i;
    }
    return facto;
}
int bino(int n, int r)
{

    int answer = factorial(n) / (factorial(r) * factorial(n - r));
    return answer;
}

int main()
{
    int a, b, answer;
    cin >> a >> b;
    if (a < b)
    {
        cout << "ENTER VALID INPUT";
    }
    else
    {

        answer = bino(a, b);
        cout << answer;
    }
}