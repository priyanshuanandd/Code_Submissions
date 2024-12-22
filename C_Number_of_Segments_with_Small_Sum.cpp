#include <string>
#include <unordered_map>
#include <climits>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        cout << n << endl;
        string strans = "";
        unordered_map<char, int> m;
        if (t.size() > n)
        {
            return strans;
        }
        if (t == s)
        {
            return s;
        }
        int l = 0;
        int curr = 0;
        int ans = 1e5 + 1;
        for (auto i : t)
        {
            m[i]++;
        }

        int cnt = m.size();
        for (int r = 0; r < n; r++)
        {
            m[s[r]]--;
            if (m[s[r]] == 0)
            {
                curr++;
            }
            // cout << "curr " << curr << " l " << l << " r " << r << endl;

            while (curr == cnt)
            {
                // cout << "HUN " << l << " " << r << " " << r-l+1 << " " << ans << endl;
                if (ans > r - l + 1)
                {
                    ans = min(ans, r - l + 1);

                    strans = s.substr(l, r - l + 1);
                }

                m[s[l]]++;
                if (m[s[l]] > 0)
                {
                    // cout << "l " << l << endl;
                    curr--;
                }
                l++;
            }
        }
        return strans;
    }
};