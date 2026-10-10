class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        int max_diff = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            max_diff = max(max_diff, diff[i]);
        }

        if (max_diff == 0)
            return 0;

        vector<int> count(max_diff + 1, 0);
        for (int d : diff) {
            count[d]++;
        }
        for (int d = max_diff; d > 0 && k > 0; --d) {
            if (count[d] == 0)
                continue;

            if (k >= count[d]) {
                k -= count[d];
                count[d - 1] += count[d];
                count[d] = 0;
            } else {
                count[d - 1] += k;
                count[d] -= k;
                k = 0;
            }
        }
        long long ans = 0;
        for (int d = 1; d <= max_diff; ++d) {
            if (count[d] > 0) {
                ans += (long long)count[d] * d * d;
            }
        }

        return ans;
    }
};