class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][j] = number of ways to make denomination j with 1st i coins
        // dp[0][0] = 1
        // dp[i][0] = 0
        // dp[0][j] = 1
        // dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= amount; j++) {
                if(i == 0) {
                    dp[i][j] = 0;
                }
                else if(j == 0) {
                    dp[i][j] = 1;
                }
                else if(j - coins[i - 1] >= 0) {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount];
    }
};