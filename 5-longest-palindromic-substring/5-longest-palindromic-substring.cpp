class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // dp[l][r] = is s[l, r] a palindrome?
        vector<vector<bool>> dp(n + 1, vector<bool> (n + 1));
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
        pair<int, int> p;
        int len = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dp[i][j]) {
                    if(j - i + 1 > len) {
                        len = j - i + 1;
                        p = {i, j};
                    }
                }
            }
        }
        return s.substr(p.first, len);
    }
};