class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        map<pair<int, int>, int> vis;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j]) {
                    ans[i][j] = 0;
                    q.push({i, j});
                    vis[{i, j}] = 1;
                }
            }
        }
        auto isValid = [&](int i, int j) {
            return (i >= 0 && j >= 0 && i < n && j < m);
        };
        int level = 1;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto u = q.front();
                q.pop();
                bool ok = vis.find({u.first, u.second + 1}) != vis.end();
                if(isValid(u.first, u.second + 1) && !ok) {
                    vis[{u.first, u.second + 1}] = 1;
                    ans[u.first][u.second + 1] = level;
                    q.push({u.first, u.second + 1});
                }
                ok = vis.find({u.first, u.second - 1}) != vis.end();
                if(isValid(u.first, u.second - 1) && !ok) {
                    vis[{u.first, u.second - 1}] = 1;
                    ans[u.first][u.second - 1] = level;
                    q.push({u.first, u.second - 1});
                }
                ok = vis.find({u.first + 1, u.second}) != vis.end();
                if(isValid(u.first + 1, u.second) && !ok) {
                    vis[{u.first + 1, u.second}] = 1;
                    ans[u.first + 1][u.second] = level;
                    q.push({u.first + 1, u.second});
                }
                ok = vis.find({u.first - 1, u.second}) != vis.end();
                if(isValid(u.first - 1, u.second) && !ok) {
                    vis[{u.first - 1, u.second}] = 1;
                    ans[u.first - 1][u.second] = level;
                    q.push({u.first - 1, u.second});
                }
            }
            level++;
        }
        return ans;
    }
};