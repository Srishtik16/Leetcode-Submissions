class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // dp[i][j] = minimum sum to reach this point (i, j)
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0] = matrix[0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
                }
                if(j + 1 < m) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + matrix[i][j]);
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};