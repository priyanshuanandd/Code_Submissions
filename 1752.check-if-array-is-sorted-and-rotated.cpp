/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] < nums[i])
            {
                count++;
            }
        }
        if (count == 1 and nums[0] > nums[nums.size() - 1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
