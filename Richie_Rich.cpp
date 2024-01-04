#include <iostream>
using namespace std;
int richie(int a, int b, int x)
{
}
int main()
{
    int count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        cout << (b-a)/x << "n";
    }

    return 0;
}