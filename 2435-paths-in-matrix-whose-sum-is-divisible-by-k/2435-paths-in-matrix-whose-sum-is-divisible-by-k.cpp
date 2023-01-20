class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int s = 0; s < k; s++) {
                    int ns = (s + grid[i][j]) % k;
                    if(i > 0) {
                        dp[i][j][ns] += dp[i - 1][j][s];
                    }
                    if(j > 0) {
                        dp[i][j][ns] += dp[i][j - 1][s];
                    }
                    dp[i][j][ns] %= MOD;
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};