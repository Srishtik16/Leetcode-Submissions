const int MOD = 1e9 + 7;
class Solution {
public:
    int distinctSequences(int n) {
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(7, vector<long long>(7, 0)));
        for(int j = 0; j <= 6; j++) {
            for(int k = 0; k <= 6; k++) {
                dp[n][j][k] = 1;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= 6; j++) {
                for(int k = 0; k <= 6; k++) {
                    for(int l = 1; l <= 6; l++) {
                        if(j != l && k != l && (j == 0 || __gcd(j, l) == 1)) {
                            dp[i][j][k] += dp[i + 1][l][j];
                            dp[i][j][k] %= MOD;
                        }
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};