class Solution {
public:
    vector<vector<long long>> minPathSum(vector<vector<long long>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) {
            dp[0][i] = grid[0][i];
        }
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp;
    }
    int minimumTotal(vector<vector<int>>& a) {
        vector<vector<long long>> triangle;
        for(auto x: a) {
            vector<long long> vals;
            for(auto y: x) {
                vals.push_back(y);
            }
            triangle.push_back(vals);
        }
        int len = triangle.back().size();
        for(auto &x: triangle) {
            while(x.size() < len) {
                x.push_back(1e12);
            }
        }
        auto ans = minPathSum(triangle);
        long long res = LLONG_MAX;
        for(int i = 0; i < ans[0].size() - 1; i++) {
            res = min(res, ans[(int)ans.size() - 2][i]);
        }
        return res;
    }
};