class Solution {
public:
    int shortestPath(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> obstacle(n, vector<int>(m));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto isValid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < m;
        };
        obstacle[0][0] = matrix[0][0];
        // {location, number of obstacles}
        queue<vector<int>> q;
        q.push({0, 0, obstacle[0][0]});
        vis[0][0] = true;
        int moves = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto info = q.front();
                q.pop();
                if(info[0] == n - 1 && info[1] == m - 1) {
                    return moves;
                }
                for(auto &dir: dirs) {
                    if(isValid(info[0] + dir.first, info[1] + dir.second)) {
                        int nx = info[0] + dir.first;
                        int ny = info[1] + dir.second;
                        int oldObs = obstacle[nx][ny];
                        int newObs = info[2] + matrix[nx][ny];
                        if(!vis[nx][ny] && newObs <= k) {
                            q.push({nx, ny, newObs});
                            obstacle[nx][ny] = newObs;
                            vis[nx][ny] = true;
                        }
                        else if(newObs < oldObs && newObs <= k) {
                            q.push({nx, ny, newObs});
                            obstacle[nx][ny] = newObs;
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};