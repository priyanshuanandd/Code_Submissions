#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int testcase = 0; testcase < n; testcase++)
    {
        int num,num2 = 0;
        cin >> num;
        for (; num != 0;)
        {
          num2 =num2 * 10 + num%10;
            num /= 10;
        }
        cout <<num2<< endl;
    }

    return 0;
}