class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j] = number of distinct subsequences of s[0...i] and t[0...j]
        // if(s[i] == t[j]) -> dp[i - 1][j - 1] added
        // else dp[i - 1][j] + dp[i][j - 1]
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = min((long long)1e12, dp[i - 1][j - 1] + dp[i - 1][j]);
                }
                else {
                    dp[i][j] = min((long long)1e12, dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};