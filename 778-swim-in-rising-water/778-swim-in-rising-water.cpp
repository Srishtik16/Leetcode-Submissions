class Solution {
public:
    const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        set<vector<int>> pq;
        pq.insert({grid[0][0], 0, 0});
        int ans = grid[0][0];
        vis[0][0] = true;
        auto isValid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < m;
        };
        while(!pq.empty()) {
            auto u = *pq.begin();
            pq.erase(pq.begin());
            ans = max(ans, u[0]);
            if(u[1] == n - 1 && u[2] == m - 1) {
                return ans;
            }
            for(auto dir: dirs) {
                int nx = u[1] + dir.first;
                int ny = u[2] + dir.second;
                if(isValid(nx, ny)) {
                    if(!vis[nx][ny]) {
                        vis[nx][ny] = true;
                        pq.insert({grid[nx][ny], nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};