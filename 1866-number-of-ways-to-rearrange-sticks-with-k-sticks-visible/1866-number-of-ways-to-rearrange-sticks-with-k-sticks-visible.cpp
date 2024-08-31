class Solution {
public:
    int rearrangeSticks(int n, int k) {
        // dp[i][j] = ans for i elements with j visible from left
        // if ith element largest
        // dp[i][j] = dp[i - 1][j - 1] (largest element will always contribute)
        // Else
        // dp[i][j] = dp[i - 1][j] * (i - 1) (i - 1 choices for ith element)
        // dp[0][0] = 1
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i - 1][j] * 1LL * (i - 1);
                dp[i][j] %= MOD;
            }
        }
        return dp[n][k];
    }
};