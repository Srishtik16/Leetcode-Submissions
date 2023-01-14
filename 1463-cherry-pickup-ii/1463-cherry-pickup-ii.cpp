class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        int ans = dp[0][0][m - 1];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    if(dp[i - 1][j][k] == -1) {
                        continue;
                    }
                    for(int x = -1; x <= 1; x++) {
                        for(int y = -1; y <= 1; y++) {
                            if(j + x >= 0 && k + y >= 0 && j + x < m && k + y < m) {
                                dp[i][j + x][k + y] = max(dp[i][j + x][k + y], dp[i - 1][j][k] + ((j + x == k + y) ? grid[i][j + x] : grid[i][j + x] + grid[i][k + y]));
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dp[n - 1][i][j]);
            }
        }
        return ans;
    }
};