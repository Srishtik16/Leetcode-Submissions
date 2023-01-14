class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp = grid;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                int mn = INT_MAX;
                if(i - 1 >= 0) {
                    mn = min(mn, dp[i - 1][j]);
                }
                if(j - 1 >= 0) {
                    mn = min(mn, dp[i][j - 1]);
                }
                dp[i][j] += mn;
            }
        }
        return dp[n - 1][m - 1];
    }
};