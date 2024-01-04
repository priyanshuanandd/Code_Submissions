/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (auto i : nums)
        {
            if (s.count(i) == 1)
            {
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};
// @lc code=end
