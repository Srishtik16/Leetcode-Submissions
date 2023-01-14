class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        using ll = long long;
        vector<ll> dp(m, 0);
        dp[0] = 1 - grid[0][0];
        for(int i = 0; i < n; i++) {
            vector<ll> new_dp(m, 0);
            if(i == 0) {
                new_dp = dp;
            }
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                if(grid[i][j]) {
                    new_dp[j] = 0;
                }
                else {
                    if(i - 1 >= 0) {
                        new_dp[j] += dp[j];
                    }
                    if(j - 1 >= 0) {
                        new_dp[j] += new_dp[j - 1];
                    }
                }
            }
            dp.swap(new_dp);
        }
        return dp[m - 1];
    }
};