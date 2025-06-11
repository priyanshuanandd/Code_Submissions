class Solution {
public:

    vector<int> nums;
    int p;
    int minimumSubarray(long long int target){
        for (auto &i : nums) {
            i %= p;
        }
        vector<long long int> pref(nums.size(),0);
        unordered_map<long long int,long long int> m;
        long long int ans  = 1e9;
        long long int n = nums.size();
        for(long long int i = 0; i < n ; i++){
            if(i!=0){
                pref[i] = ((pref[i-1])%p + (nums[i])%p)%p;
            }
            else{
                pref[0] = nums[0];
            }
            if(m.find(pref[i]-target)!=m.end()){
                ans = min(ans,i-m[pref[i]-target]);
            }
            else if(pref[i] == target){
                ans = min(ans,i+1);
            }
            m[pref[i]] = i;
        }
        return ans;
    }
    int minSubarray(vector<int>& nums, int p) {
        this->nums = nums;
        this->p = p;
        long long int n = nums.size();
        long long int sum = accumulate(nums.begin(), nums.end(), 0ll);
        long long int rem = sum % p;
        cout << rem << endl;
        if (rem == 0) {
            return 0;
        }
        // find either the number rem or rem - p
        int ans = minimumSubarray(rem);
        ans = min(minimumSubarray(rem-p),ans);
        return ans >= n ? -1 : ans;
    }
};

// 3   1   4   2 ->10
// 3   4   8   10
// 3   4   2   4