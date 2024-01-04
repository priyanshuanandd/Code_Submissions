#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;

void subsets(vector<int> &sub, int i, vector<int> &num)
{
    if (i == num.size())
    {
        v.push_back(sub);
        return;
    }

    subsets(sub, i + 1, num);

    sub.push_back(nums[i]);

    generate(sub, i + 1, num);
    sub.pop_back();
}
int main()
{
    int n;
    cin >> n;
    vector<int> num
    return 0;
}