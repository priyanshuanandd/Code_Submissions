#include <bits/stdc++.h>
#include <vector>
using namespace std;

void sortList(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (auto i : nums)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int> num;
    int value ;
    while (true)
    {
        cin >> value;
        if (value == 0 )
        {
            break;
        }
        num.push_back(value);
    }
    
   sortList(num);
    
}
