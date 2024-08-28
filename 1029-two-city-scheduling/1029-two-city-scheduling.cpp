class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // dp[i][j] = in the first i persons, j go to city a
        // For ith person, you can go to city a or not (take/not take)
        // dp[i][j] = min(dp[i - 1][j - 1] + cost a, dp[i - 1][j] + cost b)
        // dp[0][0] = 0
        // dp[i][0] = dp[i - 1][0] + cost b
        // dp[0][i] = INT_MAX
        int n = costs.size();
        n /= 2;
        vector<vector<int>> dp(2 * n + 1, vector<int>(n + 1, 1e6));
        for(int i = 0; i <= 2 * n; i++) {
            dp[i][0] = i == 0 ? 0 : dp[i - 1][0] + costs[i - 1][1];
        }
        for(int i = 1; i <= 2 * n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j - 1] + costs[i - 1][0], dp[i - 1][j] + costs[i - 1][1]);
            }
        }
        return dp[2 * n][n];
    }
};

// f(i, n) -> f(i + 1, n - 1) + cost a or f(i + 1, n) + cost b
// f(n - 1, 0) = ans