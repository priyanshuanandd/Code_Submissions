/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> vs(26, 0), vt(26, 0);

        for (auto i : s)
        {
            vs[i - 97]++;
        }

        for (auto i : t)
        {
            vt[i - 97]++;
        }

        if (vt == vs)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
