class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp = grid;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int bestValue = INT_MAX;
                for(int k = 0; k < m; k++) {
                    bestValue = min(bestValue, dp[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                }
                dp[i][j] += bestValue;
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};