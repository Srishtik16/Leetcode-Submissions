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
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for(int i = 1; i <= m; i++) {
            dp[i] = dp[i - 1] & (s2[i - 1] == s3[i - 1]);
        }
        for(int i = 1; i <= n; i++) {
            vector<bool> new_dp(m + 1, false);
            new_dp[0] = dp[0] & (s1[i - 1] == s3[i - 1]);
            for(int j = 1; j <= m; j++) {
                new_dp[j] = new_dp[j] | (dp[j] & (s1[i - 1] == s3[i + j - 1])) | (new_dp[j - 1] & (s2[j - 1] == s3[i + j - 1]));
            }
            dp = new_dp;
        }
        return dp[m];
    }
};