class Solution {
public:
    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> dp;
    int dfs(int i, int j, int prev, vector<vector<int>> &grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= prev) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int len = 0;
        for(auto &dir: dirs) {
            len = max(dfs(i + dir[0], j + dir[1], grid[i][j], grid), len);
        }
        return dp[i][j] = len + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // dp[i][j] = longest increasing path from {i, j}
        int n = matrix.size();
        int m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, -1, matrix));
            }
        }
        return ans;
    }
};