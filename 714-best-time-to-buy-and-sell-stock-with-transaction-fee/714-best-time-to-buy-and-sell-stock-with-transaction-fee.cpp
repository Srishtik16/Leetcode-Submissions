class Solution {
public:
    int recurse(int ind, bool buy, vector<int> &prices, vector<vector<int>> &dp, int fee) {
        if(ind >= prices.size()) {
            return 0;
        }
        if(dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        int profit = 0;
        if(buy) {
            profit = max(-prices[ind] + recurse(ind + 1, buy ^ 1, prices, dp, fee), recurse(ind + 1, buy, prices, dp, fee));
        }
        else {
            profit = max(prices[ind] + recurse(ind + 1, buy ^ 1, prices, dp, fee) - fee, recurse(ind + 1, buy, prices, dp, fee));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return recurse(0, 1, prices, dp, fee);
    }
};