class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n, j = m;
        string ans = "";
        while(i >= 1 && j >= 1) {
            if(s[i - 1] == t[j - 1]) {
                ans += s[i - 1];
                i--;
                j--;
            }
            else {
                if(dp[i - 1][j] > dp[i][j - 1]) {
                    ans += s[i - 1];
                    i--;
                }
                else {
                    ans += t[j - 1];
                    j--;
                }
            }
        }
        while(i >= 1) {
            ans += s[i - 1];
            i--;
        }
        while(j >= 1) {
            ans += t[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};