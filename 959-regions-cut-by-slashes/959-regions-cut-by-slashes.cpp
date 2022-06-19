class Solution {
public:
    void dfs(int i, int j, int k, vector<string> &grid, vector<vector<vector<bool>>> &vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j][k]) {
            return;
        }
        vis[i][j][k] = true;
        if(k == 0) {
            dfs(i - 1, j, 2, grid, vis);
        }
        else if(k == 1) {
            dfs(i, j + 1, 3, grid, vis);
        }
        else if(k == 2) {
            dfs(i + 1, j, 0, grid, vis);
        }
        else if(k == 3) {
            dfs(i, j - 1, 1, grid, vis);
        }
        if(grid[i][j] != '\\') {
            dfs(i, j, k ^ 3, grid, vis);
        } 
        if(grid[i][j] != '/') {
            dfs(i, j, k ^ 1, grid, vis);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(4, false)));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 4; k++) {
                    if(!vis[i][j][k]) {
                        dfs(i, j, k, grid, vis);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};