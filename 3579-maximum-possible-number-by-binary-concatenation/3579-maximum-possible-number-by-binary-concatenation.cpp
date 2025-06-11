class Solution {
public:
    static bool compare(string& a,string& b) {
        return a + b > b + a;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string> a;
        for(auto i : nums){
            string s =  bitset<32>(i).to_string();
            s = s.substr(s.find('1'));
            //cout <<i << " " <<  s << endl;
            a.push_back(s);
        }
        sort(a.begin(),a.end(),compare);
        string ans = "";
        for(int i = 0 ; i < 3 ;i++){
            ans+=a[i];
        }
       // cout << ans << endl;
        long long k = stoull(ans, nullptr, 2);
        return k;
    }
};