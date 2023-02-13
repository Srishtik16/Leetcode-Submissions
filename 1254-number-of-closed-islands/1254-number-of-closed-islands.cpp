class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j] == 1) {
            return;
        }
        vis[i][j] = true;
        dfs(i + 1, j, grid, vis);
        dfs(i - 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0 && !vis[i][0]) {
                dfs(i, 0, grid, vis);
            }
            if(grid[i][m - 1] == 0 && !vis[i][m - 1]) {
                dfs(i, m - 1, grid, vis);
            }
        }
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 0 && !vis[0][i]) {
                dfs(0, i, grid, vis);
            }
            if(grid[n - 1][i] == 0 && !vis[n - 1][i]) {
                dfs(n - 1, i, grid, vis);
            }
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(grid[i][j] == 0 && !vis[i][j]) {
                    ans++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};