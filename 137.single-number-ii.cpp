/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 3)
        {
            if (nums[i] != nums[i + 1] or nums[i + 1] != nums[i + 2])
            {
                return nums[i];
            }
        }
    }
};
// @lc code=end
