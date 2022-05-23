class Solution {
public:
    vector<pair<int, int>> dz = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool isValid(vector<vector<char>> &grid, vector<vector<bool>> &vis, int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n && !vis[x][y] && grid[x][y] == '1';
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int x, int y, int m, int n) {
        if(!isValid(grid, vis, x, y, m, n)) {
            return;
        }
        vis[x][y] = true;
        for(auto dir: dz) {
            dfs(grid, vis, x + dir.first, y + dir.second, m, n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, vis, i, j, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};