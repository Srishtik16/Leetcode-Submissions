class Solution {
public:
    int lps(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int maxProduct(string s) {
        int n = s.size();
        int ans = 0;
        auto isPalin = [&](string s) {
            string t = s;
            reverse(s.begin(), s.end());
            return s == t;
        };
        for(int mask = 1; mask < (1LL << n); mask++) {
            string s1 = "", s2 = "";
            for(int i = 0; i < n; i++) {
                if((1LL << i) & mask) {
                    s1 += s[i];
                }
                else {
                    s2 += s[i];
                }
            }
            if(isPalin(s1)) {
                ans = max(ans, (int)s1.size() * lps(s2));
            }
        }
        return ans;
    }
};