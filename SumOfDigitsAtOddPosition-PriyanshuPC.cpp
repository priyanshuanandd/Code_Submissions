#include <iostream>
using namespace std;

int main()
{
    int N, container, answer = 0;
    cin >> N;
    int New = 0, lala = 0;
    for (int i = 0; N != 0; i++)
    {
        lala = N % 10;
        N /= 10;
        New = New * 10 + lala;
    }
    cout << New << endl;
    N = New;

    for (int i = 1; N != 0; i++)
    {
        container = N % 10;
        N /= 10;
        if (i % 2 != 0)
        {
            answer = answer + container;
        }
    }
    cout << answer;
    return 0;
}