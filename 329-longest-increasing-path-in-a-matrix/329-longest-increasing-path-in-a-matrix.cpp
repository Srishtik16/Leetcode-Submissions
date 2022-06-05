class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp, int par) {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= par) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = dfs(i - 1, j, matrix, dp, matrix[i][j]);
        int down = dfs(i + 1, j, matrix, dp, matrix[i][j]);
        int left = dfs(i, j - 1, matrix, dp, matrix[i][j]);
        int right = dfs(i, j + 1, matrix, dp, matrix[i][j]);
        dp[i][j] = max({up, down, left, right}) + 1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp, -1));
            }
        }
        return ans;
    }
};