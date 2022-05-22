class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            if(i + 1 < n) {
                dp[i][i + 1] = s[i] == s[i + 1];
            }
        }
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < n - 1; i++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i][j] | dp[i + 1][j - 1];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};