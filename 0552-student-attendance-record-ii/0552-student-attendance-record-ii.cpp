class Solution {
public:
    int checkRecord(int n) {
        // dp[i][j][k] = number of ways for i days, with atmost j trailing Ls, and atmost total k absents
        // dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][2][k]
        // dp[0][j][k] = 1, dp[1][j][k] = 1
        const int MOD = 1e9 + 7;
        int dp[n + 1][3][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;
        dp[0][1][1] = 1;
        dp[0][2][1] = 1;
        dp[0][2][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 2; k++) {
                    dp[i][j][k] += dp[i - 1][2][k];
                    dp[i][j][k] %= MOD;
                    if(j - 1 >= 0) {
                        dp[i][j][k] += dp[i - 1][j - 1][k];
                        dp[i][j][k] %= MOD;
                    } 
                    if(k - 1 >= 0) {
                        dp[i][j][k] += dp[i - 1][2][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                }
            }
        }
        return dp[n][2][1];
    }
};