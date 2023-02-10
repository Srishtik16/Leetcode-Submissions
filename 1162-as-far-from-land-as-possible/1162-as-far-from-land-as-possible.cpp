const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> vis;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    vis[{i, j}] = true;
                }
            }
        }
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(auto &dir: dirs) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if(nx >= 0 && ny >= 0 && max(nx, ny) < n && !vis[{nx, ny}]) {
                        vis[{nx, ny}] = true;
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        return ans == 1 ? -1 : ans - 1;
    }
};