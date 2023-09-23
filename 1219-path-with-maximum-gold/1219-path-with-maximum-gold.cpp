class Solution {
public:
    int goldCollected;
    int ans;
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j] == 0) {
            return;
        }
        goldCollected += grid[i][j];
        ans = max(ans, goldCollected);
        vis[i][j] = true;
        dfs(i + 1, j, grid, vis);
        dfs(i - 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
        goldCollected -= grid[i][j];
        vis[i][j] = false;
        ans = max(ans, grid[i][j]);
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    goldCollected = 0;
                    dfs(i, j, grid, vis);
                    vis = vector<vector<bool>>(n, vector<bool>(m, false));
                }
            }
        }
        return ans;
    }
};