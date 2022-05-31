class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m + 1);
        for(int i = 0; i < n; i++) {
            vector<int> new_dp(m + 1);
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    new_dp[j] = grid[i][j] == 0;
                }
                else if(i == 0) {
                    if(grid[i][j] == 0) {
                        new_dp[j] += new_dp[j - 1];
                    }
                }
                else if(j == 0) {
                    if(grid[i][j] == 0) {
                        new_dp[j] += dp[j];
                    }
                }
                else {
                    if(grid[i][j] == 0) {
                        new_dp[j] += new_dp[j - 1];
                        new_dp[j] += dp[j];
                    }
                }
            }
            dp = new_dp;
        }
        return dp[m - 1];
    }
};