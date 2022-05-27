const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        auto isValid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1;
        };
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int days = -2;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto p = q.front();
                int x = p.first;
                int y = p.second;
                q.pop();
                for(auto dir: dirs) {
                    if(isValid(x + dir.first, y + dir.second)) {
                        q.push({x + dir.first, y + dir.second});
                        grid[x + dir.first][y + dir.second] = 2;
                    }
                }
            }
            days += 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return days == -2 ? 0 : days + 1;
    }
};