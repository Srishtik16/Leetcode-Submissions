class Solution {
public:
    int recurse(vector<vector<vector<int>>> &dp, vector<int> &prices, int ind, bool buy, int k) {
        if(k == 0) {
            return 0;
        }
        if(ind == (int)prices.size()) {
            return 0;
        }
        if(dp[ind][k][buy] != -1) {
            return dp[ind][k][buy];
        }
        if(buy) {
            dp[ind][k][buy] = max(recurse(dp, prices, ind + 1, buy ^ 1, k) - prices[ind], recurse(dp, prices, ind + 1, buy, k));
        }
        else {
            dp[ind][k][buy] = max(recurse(dp, prices, ind + 1, buy ^ 1, k - 1) + prices[ind], recurse(dp, prices, ind + 1, buy, k));
        }
        return dp[ind][k][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k = 2;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return recurse(dp, prices, 0, 1, k);
    }
};