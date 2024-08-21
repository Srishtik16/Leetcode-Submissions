class Solution {
public:
    int recurse(int row, int column, vector<vector<int>> &v, vector<vector<int>> &dp) {
        if(row >= (int)v.size()) {
            return 0;
        }
        if(dp[row][column] != INT_MIN) {
            return dp[row][column];
        }
        int ans = min(recurse(row + 1, column, v, dp), recurse(row + 1, column + 1, v, dp)) + v[row][column];
        dp[row][column] = ans;
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle.back().size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        int ans = recurse(0, 0, triangle, dp);
        return ans;
    }
};