/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */

// @lc code=start
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> m;
        int sum = 0;
        for (auto &i : answers)
        {

            m[i]++;
        }

        for (auto &i : m)
        {
            int j = i.first;
            int freq = i.second;
            int k = freq % (j + 1);
            sum += (freq / (j + 1)) * (j + 1);
            if (k > 0)
            {
                sum += (j + 1);
            }
        }
        return sum;
    }
};
// @lc code=end
