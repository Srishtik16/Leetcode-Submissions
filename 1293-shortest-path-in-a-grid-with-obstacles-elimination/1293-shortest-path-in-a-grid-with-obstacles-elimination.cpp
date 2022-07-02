class Solution {
public:
    const vector<int> dx = {1, 0, -1, 0};
    const vector<int> dy = {0, 1, 0, -1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        auto isValid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < m;
        };
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        bool vis[41][41][1601];
        memset(vis, false, sizeof(vis));
        queue<vector<int>> q; // {x, y, obstacles left}
        d[0][0] = 0;
        vis[0][0][k] = true;
        q.push({0, 0, k});
        int steps = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int x = q.front()[0];
                int y = q.front()[1];
                int obstacle = q.front()[2];
                q.pop();
                if(x == n - 1 && y == m - 1) {
                    return steps;
                }
                for(int i = 0; i < 4; i++) {
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    if(isValid(nx, ny)) {
                        if(grid[nx][ny] == 1 && obstacle > 0 && !vis[nx][ny][obstacle - 1]) {
                            q.push({nx, ny, obstacle - 1});
                            vis[nx][ny][obstacle - 1] = true;
                            d[nx][ny] = min(d[x][y] + 1, d[nx][ny]);
                        }
                        else if(grid[nx][ny] == 0 && !vis[nx][ny][obstacle]) {
                            q.push({nx, ny, obstacle});
                            vis[nx][ny][obstacle] = true;
                            d[nx][ny] = min(d[x][y] + 1, d[nx][ny]);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
        return d[n - 1][m - 1] == INT_MAX ? -1 : d[n - 1][m - 1];
    }
};