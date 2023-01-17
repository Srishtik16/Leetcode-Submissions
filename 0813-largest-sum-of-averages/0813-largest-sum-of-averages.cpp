class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();
        vector<double> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        // dp[i][j] = answer for 1st i elements with atmost j partitions
        // Base Case
        // dp[0][0] = 0, dp[i][0] = pref[i], dp[0][j] = 0
        // Transistions
        // dp[i][j] = max(dp[k][j - 1] + cost(k, i)) over all k from 0 to i - 1
        vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = pref[i] / i;
        }
        auto cost = [&](int l, int r) {
            return (pref[r] - pref[l]) / (r - l);
        };
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                for(int k = 1; k < K; k++) {
                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + cost(j, i));
                }
            }
        }
        return dp[n][K - 1];
    }
};