class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // dp[i][j] = size of largest subset which has atmost i zeroes and j ones if i take/not take the current string
        //dp[0][i] = all elements with only ones with total <= i
        // dp[i][0] = all elements with only zeroes with total <= i
        // dp[0][0] = 0
        // dp[i][j] = max(dp[i][j], dp[i - zeroes_in_string][j - ones_in_string]
        for(auto &x: strs) {
            for(int i = m; i >= 0; i--) {
                for(int j = n; j >= 0; j--) {
                    int zeroes = count(x.begin(), x.end(), '0');
                    int ones = x.size() - zeroes;
                    if(i - zeroes >= 0 && j - ones >= 0) {
                        dp[i][j] = max(dp[i][j], dp[i - zeroes][j - ones] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};