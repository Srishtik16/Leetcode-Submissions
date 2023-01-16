class Solution {
public:
    vector<vector<int>> dp;
    int recurse(int index, bool buy, vector<int> &prices, int fee) {
        if(index == (int)prices.size()) {
            return 0;
        }
        if(dp[index][buy] != -1) {
            return dp[index][buy];
        }
        int ans = INT_MIN;
        if(buy) {
            ans = max({ans, recurse(index + 1, buy ^ 1, prices, fee) - prices[index], recurse(index + 1, buy, prices, fee)});
        }
        else {
            ans = max({ans, recurse(index + 1, buy ^ 1, prices, fee) + prices[index] - fee, recurse(index + 1, buy, prices, fee)});
        }
        return dp[index][buy] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp = vector<vector<int>> ((int)prices.size() + 1, vector<int>(2, -1));
        return recurse(0, true, prices, fee);
    }
};