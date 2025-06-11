class Solution {
public:
    string s1 = "AB";
    string s2 = "CD";
    string f(string s) {

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (i <= s.size() - 1 and s[i] == 'A' and s[i + 1] == 'B') {
                i++;
                continue;
            } else if (i <= s.size() - 1 and s[i] == 'C' and s[i + 1] == 'D') {
                i++;
                continue;
            } else {
                ans.push_back(s[i]);
            }
        }
        if(s == ans){
            return s;
        }
        return f(ans);
    }
    int minLength(string s) {
        string a = f(s);
        return a.size();
    }
};