#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        int maxi, sum, answer = 0;
        cin >> maxi >> sum;

        if (maxi >= sum)
        {
            answer = sum;
        }
        else if (maxi < sum)
        {
            answer = 2*maxi - sum;
            if (answer < 0){
                answer = answer * -1;
            }
        }
        cout << answer<< endl;
    }
    

    return 0;
}