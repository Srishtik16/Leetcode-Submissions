class Solution {
public:
    vector<vector<bool>> vis;
    int countWays;
    void dfs(vector<vector<int>> &grid, int &good, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1 || vis[i][j]) {
            return;
        }
        if(grid[i][j] == 2) {
            if(good == 0) {
                countWays++;
            }
            return;
        }
        vis[i][j] = true;
        good--;
        dfs(grid, good, i + 1, j);
        dfs(grid, good, i - 1, j);
        dfs(grid, good, i, j + 1);
        dfs(grid, good, i, j - 1);
        good++;
        vis[i][j] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        countWays = 0;
        vis = vector<vector<bool>> (n, vector<bool>(m, false));
        int good = 1;
        int sx = -1, sy = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                good += grid[i][j] == 0;
                if(grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        dfs(grid, good, sx, sy);
        return countWays;
    }
};