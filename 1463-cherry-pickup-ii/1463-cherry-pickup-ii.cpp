class Solution {
public:
    int recurse(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        // Base Cases
        if(j1 < 0 || j1 >= (int)grid[0].size() || j2 < 0 || j2 >= (int)grid[0].size()) {
            return 0;
        }
        if(i == (int)grid.size() - 1) {
            if(j1 == j2) {
                return grid[i][j1];
            }
            else {
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        // Transitions
        int ans = 0;
        for(int x = -1; x <= 1; x++) {
            for(int y = -1; y <= 1; y++) {
                if(j1 == j2) {
                    ans = max(ans, recurse(i + 1, j1 + x, j2 + y, grid, dp) + grid[i][j1]);
                }
                else {
                    ans = max(ans, recurse(i + 1, j1 + x, j2 + y, grid, dp) + grid[i][j1] + grid[i][j2]);
                }
            }
        }
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int>(m + 1, -1)));
        return recurse(0, 0, (int)grid[0].size() - 1, grid, dp);
    }
};