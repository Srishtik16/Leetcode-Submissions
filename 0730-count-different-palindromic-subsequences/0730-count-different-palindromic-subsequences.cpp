class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int l = 2; l <= n; l++) {
            for(int i = 0; i + l <= n; i++) {
                int j = i + l - 1;
                if(s[i] == s[j]) {
                    int left = i + 1, right = j - 1;
                    dp[i][j] = 2 * dp[i + 1][j - 1];
                    while(left <= right && s[i] != s[left]) {
                        left++;
                    }
                    while(left <= right && s[i] != s[right]) {
                        right--;
                    }
                    if(left < right) {
                        dp[i][j] -= dp[left + 1][right - 1];
                    }
                    else if(left == right) {
                        dp[i][j] += 1;
                    }
                    else {
                        dp[i][j] += 2;
                    }
                    dp[i][j] += MOD;
                    dp[i][j] %= MOD;
                }
                else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                    dp[i][j] += MOD;
                    dp[i][j] %= MOD;
                }
            }
        }
        return dp[0][n - 1];
    }
};