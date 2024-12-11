class Solution {
public:
    int find_set(int v, vector<int>& parent) {
        if (parent[v] <= -1)
            return v;
        return parent[v] = find_set(parent[v], parent);
    }
    bool union_set(int a, int b, vector<int>& parent) {
        a = find_set(a, parent);
        b = find_set(b, parent);
        if (a != b) {
            parent[a] += parent[b];
            parent[b] = a;
            return true;
        } else {
            return false;
        }
    }
    int n;
    bool gcdSort(vector<int>& nums) {
        n = nums.size();
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        vector<int> parent(nums2.back() + 1, -1);
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int num = nums[j];
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    union_set(i, nums[j], parent);
                    while (num % i == 0) {
                        num /= i;
                    }
                }
            }
            if (num > 1 and nums[j]%num == 0) {
                union_set(num, nums[j], parent);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << find_set(nums[i], parent) << endl;
            if (find_set(nums[i], parent) != find_set(nums2[i], parent)) {
                return false;
            }
        }
        return true;
    }
};