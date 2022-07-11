class Solution {
public:
    const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<vector<int>, bool> vis;
        queue<vector<int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '*') {
                    q.push({0, i, j});
                    vis[{i, j}] = true;
                }
            }
        }
        auto isValid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < m && (grid[x][y] == 'O' || grid[x][y] == '*' || grid[x][y] == '#');
        };
        int steps = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto u = q.front();
                q.pop();
                if(grid[u[1]][u[2]] == '#') {
                    return steps;
                }
                for(auto &dir: dirs) {
                    int nx = u[1] + dir.first;
                    int ny = u[2] + dir.second;
                    if(isValid(nx, ny) && !vis[{nx, ny}]) {
                        vis[{nx, ny}] = true;
                        q.push({steps, nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};