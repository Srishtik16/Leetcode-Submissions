const int MOD = 1e9 + 7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // target, number of dice used changes
        // dp[i][j] = number of ways to use 1st i dice to make a sum of j
        // dp[n][target] = ans
        // Base Case:
        // dp[0][j] = 0; but dp[0][0] = 1;
        // dp[i][0] = 1;
        // Transitions:
        // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j - 2] + dp[i - 1][j - k] where j - k >= 0
        vector<vector<long long>> dp(n + 1, vector<long long> (target + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                for(int dice = 1; dice <= k; dice++) {
                    if(j - dice >= 0) {
                        dp[i][j] += dp[i - 1][j - dice];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        return dp[n][target] % MOD;
    }
};