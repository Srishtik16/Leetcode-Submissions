class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberWays(vector<vector<int>>& hats) {
        // dp[i][mask] = no. of ways for 1st i hats to be paired to mask people
        // Sum dp[i - 1][mask ^ set_bit]
        int n = hats.size();
        map<int, vector<int>> adj;
        for(int i = 0; i < n; i++) {
            for(auto x: hats[i]) {
                adj[x].push_back(i);
            }
        }
        vector<vector<int>> dp(41, vector<int>(1 << n, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= 40; i++) {
            for(int j = 0; j < (1 << n); j++) {
                dp[i][j] = dp[i - 1][j] % MOD;
                for(auto k: adj[i]) {
                    if((1 << k) & j) {
                        dp[i][j] += dp[i - 1][j ^ (1 << k)];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        return dp[40][(1 << n) - 1] % MOD;
    }
};