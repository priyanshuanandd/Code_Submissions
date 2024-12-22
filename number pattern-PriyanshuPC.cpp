#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int inc = i;
        for (int spaces = 1; spaces <= N - i; spaces++)
        {
            cout << " ";
        }
        for (; inc <= 2 * i - 1; inc++)
        {
            cout << inc;
        }
        while ṇ(inc-2 >= i )
        {
            cout << inc -2;
            inc--;
        }
        
        cout << endl;
    }

    return 0;
}