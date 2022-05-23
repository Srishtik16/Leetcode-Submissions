class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int> (n + 1)));
        for(int i = 1; i <= strs.size(); i++) {
            int zero = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int one = strs[i - 1].size() - zero;
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {
                    if(j - zero >= 0 && k - one >= 0) {
                        dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - zero][k - one]);
                    }
                    else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};