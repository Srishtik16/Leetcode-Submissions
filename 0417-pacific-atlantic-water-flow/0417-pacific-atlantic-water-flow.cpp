class Solution {
public:
    set<vector<int>> pacific, atlantic;
    vector<vector<bool>> visp, visa;
    void dfs(int i, int j, int prev, vector<vector<int>> &heights, set<vector<int>> &ocean, vector<vector<bool>> &vis) {
        if(i < 0 || j < 0 || i >= vis.size() || j >= vis[0].size() || vis[i][j]) {
            return;
        }
        if(heights[i][j] < prev) {
            return;
        }
        vis[i][j] = true;
        ocean.insert({i, j});
        dfs(i, j + 1, heights[i][j], heights, ocean, vis);
        dfs(i, j - 1, heights[i][j], heights, ocean, vis);
        dfs(i - 1, j, heights[i][j], heights, ocean, vis);
        dfs(i + 1, j, heights[i][j], heights, ocean, vis);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        pacific.clear();
        atlantic.clear();
        visp = vector<vector<bool>>(n, vector<bool>(m, false));
        visa = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            dfs(i, 0, -1, heights, pacific, visp);
            dfs(i, m - 1, -1, heights, atlantic, visa);
        }
        for(int i = 0; i < m; i++) {
            dfs(0, i, -1, heights, pacific, visp);
            dfs(n - 1, i, -1, heights, atlantic, visa);
        }
        vector<vector<int>> ans;
        for(auto x: pacific) {
            if(atlantic.find(x) != atlantic.end()) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};