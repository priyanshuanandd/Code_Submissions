/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &v, int x)
    {
        if (v.size() == 0)
        {
            return {-1, -1};
        }
        int s = 0;
        int e = v.size() - 1;

        int min = 1e9;
        while (e - s > 1)
        {
            int mid = (e + s) / 2;
            if (v[mid] >= x)
            {
                if (v[mid] == x and mid < min)
                {
                    min = mid;
                }
                e = mid - 1;
            }
            else
            {

                s = mid ;
            }
        }

        e = v.size() - 1;
        s = 0;
        int max = -1;
        while (e - s > 1)
        {
            int mid = (e + s) / 2;
            if (v[mid] > x)
            {
                e = mid - 1;
            }
            else
            {
                if (v[mid] == x and mid > max)
                {
                    max = mid;
                }
                s = mid;
            }
        }
        if (min == 1e9 and max == -1)
        {
            return {-1, -1};
        }
        else
        {
            v = {min, max};
            return v;
        }
    }
};
// @lc code=end
