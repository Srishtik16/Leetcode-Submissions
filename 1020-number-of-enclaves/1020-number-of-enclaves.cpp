class Solution {
public:
    int ans;
    void dfs(int x, int y, vector<vector<int>> &grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) {
            return;
        }
        grid[x][y] = 2;
        ans++;
        dfs(x + 1, y, grid);
        dfs(x - 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        ans = 0;
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                dfs(i, 0, grid);
            }
            if(grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid);
            }
        }
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 1) {
                dfs(0, i, grid);
            }
            if(grid[n - 1][i] == 1) {
                dfs(n - 1, i, grid);
            }
        }
        ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};