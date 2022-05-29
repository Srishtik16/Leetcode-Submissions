const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
        vector<vector<int>> dist(n + 1, vector<int>(m + 1, INT_MAX));
        vis[0][0] = true;
        dist[0][0] = 0;
        while(!q.empty()) {
            auto u = q.front();
            q.pop_front();
            for(auto dir: dirs) {
                int x = u.first + dir.first;
                int y = u.second + dir.second;
                if(isValid(x, y) && !vis[x][y] && grid[x][y] == 1) {
                    dist[x][y] = min(dist[x][y], dist[u.first][u.second] + 1);
                    q.push_back({x, y});
                    vis[x][y] = true;
                }
                else if(isValid(x, y) && !vis[x][y] && grid[x][y] == 0) {
                    dist[x][y] = min(dist[x][y], dist[u.first][u.second] + 0);
                    q.push_front({x, y});
                    vis[x][y] = true;
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};