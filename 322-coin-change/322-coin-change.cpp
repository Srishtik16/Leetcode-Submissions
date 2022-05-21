class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, INT_MAX - 1));
        //dp[i][j] --> minimum coins needed to form target = j using first i denominations
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= target; i++) {
            dp[0][i] = INT_MAX - 1;
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                if(j - coins[i - 1] >= 0) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target] == INT_MAX - 1 ? -1 : dp[n][target];
    }
};