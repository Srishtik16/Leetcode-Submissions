class Solution {
public:
    int recurse(int l, int r, vector<vector<int>> &dp) {
        if(l > r) {
            return 0;
        }
        if(l == r) {
            return 0;
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int ans = INT_MAX;
        for(int i = l; i <= r; i++) {
            ans = min(ans, i + max(recurse(l, i - 1, dp), recurse(i + 1, r, dp)));
        }
        dp[l][r] = ans;
        return dp[l][r];
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return recurse(1, n, dp);
    }
};