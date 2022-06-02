const int MOD = 1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        if(n <= 2) {
            return n;
        }
        vector<long long> dp(n + 1, 1);
        dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] * 2 + dp[i - 3];
            dp[i] %= MOD;
        }
        return dp.back();
    }
};