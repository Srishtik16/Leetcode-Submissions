class Solution {
public:
    const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
    int recurse(int i1, int j1, int i2, int j2, vector<vector<int>> &grid, int dp[][55][55][55]) {
        if(j1 < 0 || j1 >= (int)grid[0].size() || j2 < 0 || j2 >= (int)grid[0].size() || i1 < 0 || i1 >= (int)grid.size() || i2 < 0 || i2 >= (int)grid.size() || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
            return INT_MIN;
        }
        if(i1 == grid.size() - 1 && i2 == grid.size() - 1) {
            if(j1 == grid[0].size() - 1 && j2 == grid[0].size() - 1) {
                return grid[i1][j1];
            }
        }
        if(dp[i1][j1][i2][j2] != INT_MIN) {
            return dp[i1][j1][i2][j2];
        }
        int ans = INT_MIN;
        for(auto dir1: dirs) {
            for(auto dir2: dirs) {
                if(i1 == i2 && j1 == j2) {
                    ans = max(ans, recurse(i1 + dir1.first, j1 + dir1.second, i2 + dir2.first, j2 + dir2.second, grid, dp) + (grid[i1][j1] == 1));
                }
                else {
                    ans = max(ans, recurse(i1 + dir1.first, j1 + dir1.second, i2 + dir2.first, j2 + dir2.second, grid, dp) + (grid[i1][j1] == 1) + (grid[i2][j2] == 1));
                }
            }
        }
        dp[i1][j1][i2][j2] = ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[55][55][55][55];
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < 55; i++) {
            for(int j = 0; j < 55; j++) {
                for(int k = 0; k < 55; k++) {
                    for(int l = 0; l < 55; l++) {
                        dp[i][j][k][l] = INT_MIN;
                    }
                }
            }
        }
        return max(0, recurse(0, 0, 0, 0, grid, dp));
    }
};