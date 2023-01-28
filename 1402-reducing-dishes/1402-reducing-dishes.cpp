class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        // dp[i][j] = maximum profit out of 1st i elements if we take j elements
        // Base Case
        // dp[0][0] = 0
        // dp[0][i] = 0
        // dp[i][0] = 0
        // Transistions
        // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + j * a[j - 1])
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                if(j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + j * a[i - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + j * a[i - 1]);
                }
            }
        }
        return *max_element(dp[n].begin(), dp[n].end());
    }
};