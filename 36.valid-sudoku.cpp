/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, int> m;
        int j = 0;
        bool flag = true;
        while (j <= 9)
        {
            m.clear();
            for (int i = 0; i < 10; i++)
            {
                m[board[j][i]]++;
                if (m[board[j][i]] > 1)
                {
                    return false;
                }
            }
            j++;
        }
        m.clear();
        while (j <= 9)
        {
            m.clear();
            for (int i = 0; i < 10; i++)
            {
                m[board[i][j]]++;
                if (m[board[i][j]] > 1)
                {
                    return false;
                }
            }
            j++;
        }
        m.clear();
        for (int i = 0; i <= 6; i += 3)
        {
            m.clear();
            for (int k = i; k < i + 3; k++)
            {
                for (int l = i; l < i + 3; l++)
                {
                    m[board[k][l]]++;
                    if (m[board[k][l]] > 1)
                    {
                        return false;
                    }
                }
            }
        }
    }
};
// @lc code=end
