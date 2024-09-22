class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // dp[i][j] = minimum moves to make s[0...i] and t[0...j] equal
        // if last chars equal dp[i][j] = dp[i - 1][j - 1]
        // else we delete either last character of 1st string or second string
        // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[n][m];
    }
};