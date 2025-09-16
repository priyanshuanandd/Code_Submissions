class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int max_length = 0;
        // Sliding window approach with:
        //   nums1
        //       nums2
        // and we move nums1 one position to the right until we finish
        //           nums1
        //       nums1
        // We perform n + m steps and at every step we perform min(n, m)
        // comparisons.
        // Assuming n <= m, we have O( (n+m)*n ) -> O( n^2 + nm) -> O(nm)
        for (int i = -n + 1; i < n + m; ++i) {
            int nums1_start =
                i <= 0 ? -i : 0;              // Once i >= 0 we always tart at 0
            int nums2_start = i <= 0 ? 0 : i; // We start at zero while i <= 0
            int overlap_len =
                min(n - nums1_start,
                    m - nums2_start); // How much overlap do we have

            if (overlap_len < max_length)
                break; // Optimization: There is no chance we can find a larger
                       // subarray

            int current_length = 0;
            for (int j = 0; j < overlap_len; ++j) {
                if (nums1[nums1_start + j] == nums2[nums2_start + j]) {
                    max_length = max(++current_length, max_length);
                } else {
                    if (overlap_len - j < max_length)
                        break; // Optimization: There is no chance we can find a
                               // larger subarray
                    current_length = 0;
                }
            }
        }

        return max_length;
    }
};