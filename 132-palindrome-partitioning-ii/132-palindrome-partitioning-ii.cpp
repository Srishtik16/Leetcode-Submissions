class Solution {
public:
    int recurse(int i, string &s, int n, vector<vector<bool>> &dp, vector<int> &cutDp) {
        if(i == n) {
            return 0;
        }
        if(cutDp[i] != -1) {
            return cutDp[i];
        }
        int ans = INT_MAX;
        for(int j = i; j < n; j++) {
            if(dp[i][j]) {
                ans = min(ans, 1 + recurse(j + 1, s, n, dp, cutDp));
            }
        }
        return cutDp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (n + 1, false));
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            if(i + 1 < n) {
                if(s[i] == s[i + 1]) {
                    dp[i][i + 1] = true;
                }
                else {
                    dp[i][i + 1] = false;
                }
            }
        }
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < n - 1; i++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i][j] | dp[i + 1][j - 1];
                }
            }
        }
        vector<int> cutDp(n + 1, -1);
        return recurse(0, s, n, dp, cutDp) - 1;
    }
};