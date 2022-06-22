class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<bool>> vis;
    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
    }
    bool dfs(int x, int y, int px, int py) {
        if(vis[x][y]) {
            return false;
        }
        vis[x][y] = true;
        if(isValid(x + 1, y) && grid[x][y] == grid[x + 1][y]) {
            if(vis[x + 1][y] && (x + 1 != px && y != py)) {
                return true;
            }
            if(dfs(x + 1, y, x, y)) {
                return true;
            }
        }
        if(isValid(x - 1, y) && grid[x][y] == grid[x - 1][y]) {
            if(vis[x - 1][y] && (x - 1 != px && y != py)) {
                return true;
            }
            if(dfs(x - 1, y, x, y)) {
                return true;
            }
        }
        if(isValid(x, y + 1) && grid[x][y] == grid[x][y + 1]) {
            if(vis[x][y + 1] && (x != px && y + 1 != py)) {
                return true;
            }
            if(dfs(x, y + 1, x, y)) {
                return true;
            }
        }
        if(isValid(x, y - 1) && grid[x][y] == grid[x][y - 1]) {
            if(vis[x][y - 1] && (x != px && y - 1 != py)) {
                return true;
            }
            if(dfs(x, y - 1, x, y)) {
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& _grid) {
        grid = _grid;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> _vis(n + 1, vector<bool>(m + 1, false));
        vis = _vis;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};