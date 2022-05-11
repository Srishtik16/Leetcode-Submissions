class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (5, 0));
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 5; j++) {
                for(int k = j; k < 5; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        return dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4];
    }
};