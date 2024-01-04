#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> v;
    int s = 0;
    int e = nums.size() - 1;
    cout << s << " " << e << endl;
    int mid;
    int posmax, posmin;
    posmax = -1;
    posmin = __INT_MAX__;
    while (e - s > 1)
    {
        mid = (s + e) / 2;
        if (nums[mid] > target)
        {

            e = mid;
        }
        else
        {
            if (nums[mid] == target)
            {

                if (mid > posmax)
                {
                    posmax = mid;
                }
                if (mid < posmin)
                {
                    posmin = mid;
                }
            }
            s = mid;
        }
    }
    cout << s << " " << e << endl;
    if (nums[s] != target and nums[e] != target)
    {
        v = {-1, -1};
        return v;
    }
    else
    {
        if (posmax == -1 or posmin == __INT_MAX__)
        {
            int s = (nums[s] == target) == ? s : e;

            v = {s, s};
            return s;
        }

        v = {posmin, posmax};
        return v;
    }
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> v = searchRange(nums, target);
    for (auto i : v)
    {
        cout << i << endl;
    }
}
