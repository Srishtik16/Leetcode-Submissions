class Solution {
public:
    vector<int> best;
    vector<int> curr;
    int mx;
    int distance(int a, int b, int c, int d) {
        return abs(a - c) + abs(b - d);
    }
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j] == 0) {
            return;
        }
        if(distance(i, j, curr[0], curr[1]) > mx) {
            mx = distance(i, j, curr[0], curr[1]);
            best = {i, j};
        }
        vis[i][j] = true;
        dfs(i + 1, j, grid, vis);
        dfs(i - 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && land[i][j] == 1) {
                    best = {i, j};
                    curr = {i, j};
                    mx = 0;
                    dfs(i, j, land, vis);
                    ans.push_back({i, j, best[0], best[1]});
                }
            }
        }
        return ans;
    }
};