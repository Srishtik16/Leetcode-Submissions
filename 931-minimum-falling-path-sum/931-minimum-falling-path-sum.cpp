class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m + 1);
        for(int i = 0; i < m; i++) {
            dp[i] = matrix[0][i];
        }
        for(int i = 1; i < n; i++) {
            vector<int> new_dp(m + 1);
            for(int j = 0; j < m; j++) {
                int val = INT_MAX;
                if(j - 1 >= 0) {
                    val = min(val, dp[j - 1]);
                }
                val = min(val, dp[j]);
                if(j + 1 < m) {
                    val = min(val, dp[j + 1]);
                }
                new_dp[j] = val + matrix[i][j];
            }
            dp = new_dp;
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};