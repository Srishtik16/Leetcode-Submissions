class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        map<int, vector<vector<int>>, greater<int>> groups;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> dpRow(n), dpCol(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                groups[mat[i][j]].push_back({i, j});
            }
        }
        vector<vector<int>> dp(n, vector<int>(m));
        for(auto &group: groups) {
            if(group.second.empty()) {
                continue;
            }
            int vRow = 0;
            int vCol = 0;
            for(auto cell: group.second) {
                int x = cell[0], y = cell[1];
                vRow = dpRow[x];
                vCol = dpCol[y];
                dp[x][y] = max(vRow, vCol) + 1;
            }
            for(auto cell: group.second) {
                dpRow[cell[0]] = max(dpRow[cell[0]], dp[cell[0]][cell[1]]);
                dpCol[cell[1]] = max(dpCol[cell[1]], dp[cell[0]][cell[1]]);
            }
        }
        return max(*max_element(dpRow.begin(), dpRow.end()), *max_element(dpCol.begin(), dpCol.end()));
    }
};

// I can visit every distinct elements of a row or column
// start from largest value