const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) {
            return -1;
        }
        int path = 1;
        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push({0, 0});
        vis[0][0] = true;
        auto isValid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < n && !vis[x][y] && grid[x][y] == 0;
        };
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();
                if(x == n - 1 && y == n - 1) {
                    return path;
                }
                for(auto &[dx, dy]: dirs) {
                    int nx = x + dx, ny = y + dy;
                    if(isValid(nx, ny)) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            path++;
        }
        return -1;
    }
};