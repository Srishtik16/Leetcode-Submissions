class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] = max dot product of subsequences [0....i] and [0....j]
        // dp[i][j] = max(dp[i - 1][j - 1] + (a[i] * b[j]), dp[i - 1][j], dp[i][j - 1])
        int n = nums1.size(), m = nums2.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1e9));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = max({dp[i - 1][j - 1] + (nums1[i - 1] * 1LL * nums2[j - 1]), dp[i - 1][j], dp[i][j - 1], nums1[i - 1] * 1LL * nums2[j - 1]});
            }
        }
        return dp[n][m];
    }
};