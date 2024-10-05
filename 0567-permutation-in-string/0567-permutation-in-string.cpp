class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            hash[s1[i] - 'a']++;
        }

        vector<int> curr(26, 0);

        if (s2.size() < s1.size())
            return false;

        int l = 0;
        int r = 0;
        for (; r < s1.size(); r++) {
            curr[s2[r] - 'a']++;
        }
        for (auto i : hash) {
            cout << i << " ";
        }
        cout << endl;
        if (curr == hash)
            return true;
        for (; r < s2.size(); r++) {
            curr[s2[l] - 'a']--;
            l++;
            curr[s2[r] - 'a']++;
            // for (auto i : curr) {
            //     cout << i << " ";
            // }
            // cout << endl;
            if (curr == hash)
                return true;
        }

        return false;
    }
};