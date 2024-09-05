class Solution {
public:
    long long dp[5001][6][16];
    const int MOD = 1e9 + 7;
    long long recurse(int i, int j, int k, int n, vector<int> &r) {
        if(k > r[j]) {
            return 0;
        }
        if(i == n - 1) {
            return 1;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        long long ans = recurse(i + 1, j, k + 1, n, r) % MOD;
        ans %= MOD;
        for(int val = 0; val < 6; val++) {
            if(val == j) {
                continue;
            }
            ans += recurse(i + 1, val, 1, n, r) % MOD;
            ans %= MOD;
        }
        return dp[i][j][k] = ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        // dp[i][j][k] = answer for first i rolls with j on ith turn k consecutive times
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for(int i = 0; i < 6; i++) {
            ans += recurse(0, i, 1, n, rollMax) % MOD;
            ans %= MOD;
        }
        return ans;
    }
};