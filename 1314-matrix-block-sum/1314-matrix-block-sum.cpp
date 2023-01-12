class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = mat[0][0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + mat[i][0];
        }
        for(int i = 1; i < m; i++) {
            dp[0][i] = dp[0][i - 1] + mat[0][i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int fromRow = max(0, i - k), fromCol = max(0, j - k), toRow = min(n - 1, i + k), toCol = min(m - 1, j + k);
                int sum = dp[toRow][toCol] - (fromCol - 1 >= 0 ? dp[toRow][fromCol - 1] : 0) - (fromRow - 1 >= 0 ? dp[fromRow - 1][toCol] : 0) + (fromCol - 1 >= 0 && fromRow - 1 >= 0 ? dp[fromRow - 1][fromCol - 1] : 0);
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};