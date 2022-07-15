class Solution {
public:
    int cc = 0;
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j]) {
            return;
        }
        cc++;
        vis[i][j] = true;
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
        dfs(i + 1, j, grid, vis);
        dfs(i - 1, j, grid, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    cc = 0;
                    dfs(i, j, grid, vis);
                    ans = max(ans, cc);
                }
            }
        }
        return ans;
    }
};