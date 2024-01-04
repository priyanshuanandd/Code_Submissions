/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = (s + e) / 2;
        while (e - s < 1)
        {
            if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid;
            }
        }
        if (nums[s] == n or nums[e] == n)
        {
            int ans = nums[s] == n ? s : e;
            cout << ans << endl;
        }
    }
};
// @lc code=end
