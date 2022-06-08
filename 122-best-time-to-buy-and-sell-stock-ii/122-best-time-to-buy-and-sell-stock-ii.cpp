class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][j] = maximum profit to be obtained on prefix of first i days if buy/sell on ith day
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(dp[i + 1][1] + prices[i], dp[i + 1][0]);
            dp[i][1] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
        }
        return dp[0][1];
    }
};