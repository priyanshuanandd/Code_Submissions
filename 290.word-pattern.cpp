/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> v;
        int i = 0;
        string s2;
        while (true)
        {
            s2.clear();
            while (s[i] != ' ' and i < s.size())
            {
                s2.push_back(s[i]);
                i++;
            }
            i++;

            v.push_back(s2);

            if(i == s.size()){

                break;
            }
        }

        if (v.size() != pattern.size())
        {
            return false;
        }

        map<string, int> ms;
        map<char, string> mc;

        for (int i = 0; i < v.size(); i++)
        {
            if (ms[v[i]] == 0)
            {
                ms[v[i]] = s[i];
            }
            if (mc[s[i]].empty())
            {
                mc[s[i]] = v[i];
            }

            if (ms[v[i]] != (int)s[i])
            {
                return false;
            }
            if (mc[s[i]] != v[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
