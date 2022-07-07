class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        if(n + m != k) {
            return false;
        }
        // dp[i][j] = Is the string formed by the prefix i of s1 and prefix j of s2
        // an interleaving of the prefix i + j of s3?
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] & (s1[i - 1] == s3[i - 1]);
        }
        for(int i = 1; i <= m; i++) {
            dp[0][i] = dp[0][i - 1] & (s2[i - 1] == s3[i - 1]);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j] | (dp[i - 1][j] & (s1[i - 1] == s3[i + j - 1])) | (dp[i][j - 1] & (s2[j - 1] == s3[i + j - 1]));
            }
        }
        return dp[n][m];
    }
};