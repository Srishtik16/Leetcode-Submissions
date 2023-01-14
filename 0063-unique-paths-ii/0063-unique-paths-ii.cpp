class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        using ll = long long;
        vector<vector<ll>> dp(n, vector<ll>(m, 0));
        dp[0][0] = 1 - grid[0][0];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                if(grid[i][j]) {
                    dp[i][j] = 0;
                }
                else {
                    if(i - 1 >= 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if(j - 1 >= 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};