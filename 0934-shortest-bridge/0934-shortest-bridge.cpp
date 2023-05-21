class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    goto out;
                }
            }
        }
        out:
        queue<vector<int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        auto isValid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != 2;
        };
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int level = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto f = q.front();
                q.pop();
                for(auto &dir: dirs) {
                    int nx = f[0] + dir.first;
                    int ny = f[1] + dir.second;
                    if(isValid(nx, ny)) {
                        if(grid[nx][ny] == 1) {
                            goto last;
                        }
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }
        last:
        return level;
    }
};