class Solution {
public:
    bool solve(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 1) {
                for(int j = 0; j < n; j++) {
                    grid[j][i] = (grid[j][i] == 1 ? 0 : 1);
                }
            }
        }
        for(int i = 1; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                cnt += grid[i][j] == 1;
            }
            if(cnt != 0 && cnt != m) {
                return false;
            }
        }
        return true;
    }
    bool removeOnes(vector<vector<int>>& grid) {
        vector<vector<int>> gridFlip = grid;
        for(auto &x: gridFlip[0]) {
            x = (x == 1 ? 0 : 1);
        }
        bool ok = solve(grid);
        ok |= solve(gridFlip);
        return ok;
    }
};