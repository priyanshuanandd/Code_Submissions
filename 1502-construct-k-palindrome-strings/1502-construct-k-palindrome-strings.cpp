class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26,0);
        for(int i = 0; i < s.size() ; i++){
            cnt[s[i]-'a']++;
        }
        int odd = 0;
        for(auto i : cnt){
            odd += (i%2);
        }

        return (odd <= k and k<=s.size());
    }
};