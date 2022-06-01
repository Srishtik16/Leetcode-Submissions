class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int val = INT_MAX;
                if(j - 1 >= 0) {
                    val = min(val, dp[i - 1][j - 1]);
                }
                val = min(val, dp[i - 1][j]);
                if(j + 1 < m) {
                    val = min(val, dp[i - 1][j + 1]);
                }
                dp[i][j] = val + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};