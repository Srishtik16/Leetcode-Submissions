class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefR(n, vector<int>(m));
        vector<vector<int>> suffR = prefR;
        vector<vector<int>> prefC(m, vector<int>(n));
        vector<vector<int>> suffC = prefC;
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == '0' || grid[i][0] == 'W') {
                prefR[i][0] = 0;
            }
            else {
                prefR[i][0] = 1;
            }
            for(int j = 1; j < m; j++) {
                if(grid[i][j] == 'W') {
                    prefR[i][j] = 0;
                }
                else if(grid[i][j] == '0') {
                    prefR[i][j] = prefR[i][j - 1];
                }
                else {
                    prefR[i][j] = prefR[i][j - 1] + 1;
                }
            }
            if(grid[i][m - 1] == '0' || grid[i][m - 1] == 'W') {
                suffR[i][m - 1] = 0;
            }
            else {
                suffR[i][m - 1] = 1;
            }
            for(int j = m - 2; j >= 0; j--) {
                if(grid[i][j] == 'W') {
                    suffR[i][j] = 0;
                }
                else if(grid[i][j] == '0') {
                    suffR[i][j] = suffR[i][j + 1];
                }
                else {
                    suffR[i][j] = suffR[i][j + 1] + 1;
                }
            }
        }
        swap(n, m);
        for(int i = 0; i < n; i++) {
            if(grid[0][i] == '0' || grid[0][i] == 'W') {
                prefC[i][0] = 0;
            }
            else {
                prefC[i][0] = 1;
            }
            for(int j = 1; j < m; j++) {
                if(grid[j][i] == 'W') {
                    prefC[i][j] = 0;
                }
                else if(grid[j][i] == '0') {
                    prefC[i][j] = prefC[i][j - 1];
                }
                else {
                    prefC[i][j] = prefC[i][j - 1] + 1;
                }
            }
            if(grid[m - 1][i] == '0' || grid[m - 1][i] == 'W') {
                suffC[i][m - 1] = 0;
            }
            else {
                suffC[i][m - 1] = 1;
            }
            for(int j = m - 2; j >= 0; j--) {
                if(grid[j][i] == 'W') {
                    suffC[i][j] = 0;
                }
                else if(grid[j][i] == '0') {
                    suffC[i][j] = suffC[i][j + 1];
                }
                else {
                    suffC[i][j] = suffC[i][j + 1] + 1;
                }
            }
        }
        swap(n, m);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0') {
                    int LR = prefR[i][j] + (j + 1 >= m ? 0 : suffR[i][j + 1]);
                    int UD = prefC[j][i] + (i + 1 >= n ? 0 : suffC[j][i + 1]);
                    ans = max(ans, LR + UD);
                }
            }
        }
        return ans;
    }
};