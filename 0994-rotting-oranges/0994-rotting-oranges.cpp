const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        if(q.empty()) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1) {
                        return -1;
                    }
                }
            }
            return 0;
        }
        auto isValid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1  && !vis[x][y];
        };
        int days = -1;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();
                for(auto &[dx, dy]: dirs) {
                    if(isValid(x + dx, y + dy)) {
                        vis[x + dx][y + dy] = true;
                        q.push({x + dx, y + dy});
                    }
                }
            }
            days++;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0 && !vis[i][j]) {
                    return -1;
                }
            }
        }
        return days;
    }
};