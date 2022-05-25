class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        dp[0][0] = grid[0][0] == 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                else if(i == 0) {
                    if(grid[i][j] == 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
                else if(j == 0) {
                    if(grid[i][j] == 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                }
                else {
                    if(grid[i][j] == 0) {
                        dp[i][j] += dp[i][j - 1];
                        dp[i][j] += dp[i - 1][j];
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return dp[n - 1][m - 1];
    }
};