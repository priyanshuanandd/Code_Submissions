#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int elements;
        cin >> elements;
        int arr[elements];
        for (size_t i = 0; i < elements; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + elements);
        pair<int, int> number = {arr[0], arr[elements - 1]};
        cout << number.second -  number.first << endl;
    }
    return 0;
}