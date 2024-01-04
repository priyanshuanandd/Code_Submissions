#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int length, width, cost;
        cin >> length >> width >> cost;
        cout  << cost *2 * (length+width) << endl;
    }
    return 0;
}