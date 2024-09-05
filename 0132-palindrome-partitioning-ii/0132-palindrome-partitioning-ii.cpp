class Solution {
public:
    int dp[2001][2001];
    vector<vector<bool>> dpPal;
    bool isPalin(int l, int r) {
        return dpPal[l][r];
    }
    int recurse(int i, int j, string &s) {
        if(i > j) {
            return -1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i; k <= j; k++) {
            if(isPalin(i, k)) {
                ans = min(ans, recurse(k + 1, j, s) + 1);
            }
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        // if I put a cut at k, and [i, k] is palindrome then solve for (k + 1, j)
        // dp[i][j] = isPalindrome(i, k) ? recurse(k + 1, j) + 1 : continue
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        dpPal = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
        for(int i = 0; i <= n; i++) {
            dpPal[i][i] = true;
            if(i + 1 < n && s[i] == s[i + 1]) {
                dpPal[i][i + 1] = true;
            }
        }
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < n - 1; i++) {
                dpPal[i][j] = (s[i] == s[j]) && (dpPal[i][j] | dpPal[i + 1][j - 1]);
            }
        }
        return recurse(0, n - 1, s);
    }
};