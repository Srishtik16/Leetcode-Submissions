class Solution {
public:
    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        auto check = [&](int t) {
            if(grid[0][0] > t) {
                return false;
            }
            queue<vector<int>> q;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            q.push({0, 0});
            vis[0][0] = true;
            while(!q.empty()) {
                int qs = q.size();
                while(qs--) {
                    int x = q.front()[0], y = q.front()[1];
                    q.pop();
                    for(auto &dir: dirs) {
                        int nx = x + dir[0], ny = y + dir[1];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] <= t) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            return vis[n - 1][n - 1] == true;
        };
        int l = 0, r = n * n + 5, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};