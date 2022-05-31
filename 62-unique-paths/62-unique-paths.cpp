class Solution {
public:
    int uniquePaths(int m, int n) {
        swap(m, n);
        vector<long long> dp(m + 1, 0);
        for(int i = 0; i < n; i++) {
            vector<long long> new_dp(m + 1, 0);
            if(i == 0) {
                new_dp[0] = 1;
            }
            else {
                new_dp[0] = dp[0];
            }
            for(int j = 1; j < m; j++) {
                new_dp[j] = new_dp[j - 1] + dp[j];
            }
            dp = new_dp;
        }
        return dp[m - 1];
    }
};