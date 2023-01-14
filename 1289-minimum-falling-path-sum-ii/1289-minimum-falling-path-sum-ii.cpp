class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // dp[i][j] = minimum sum to reach this point (i, j)
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0] = matrix[0];
        for(int i = 1; i < n; i++) {
            vector<int> pref(m), suff(m);
            pref[0] = dp[i - 1][0];
            suff[m - 1] = dp[i - 1][m - 1];
            for(int j = 1; j < m; j++) {
                pref[j] = min(pref[j - 1], dp[i - 1][j]);
            }
            for(int j = m - 2; j >= 0; j--) {
                suff[j] = min(suff[j + 1], dp[i - 1][j]);
            }
            for(int j = 0; j < m; j++) {
                int mn = 1e9;
                if(j > 0) {
                    mn = min(mn, pref[j - 1]);
                }
                if(j < m - 1) {
                    mn = min(mn, suff[j + 1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};