class Solution {
public:
    vector<vector<vector<int>>> dp;
    int recurse(int index, bool buy, int times, vector<int> &prices) {
        if(times <= 0) {
            return 0;
        }
        if(index == (int)prices.size()) {
            return 0;
        }
        if(dp[index][buy][times] != -1) {
            return dp[index][buy][times];
        }
        int ans = INT_MIN;
        if(buy) {
            ans = max({ans, recurse(index + 1, buy ^ 1, times, prices) - prices[index], recurse(index + 1, buy, times, prices)});
        }
        else {
            ans = max({ans, recurse(index + 1, buy ^ 1, times - 1, prices) + prices[index], recurse(index + 1, buy, times, prices)});
        }
        return dp[index][buy][times] = ans;
    }
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<vector<int>>> ((int)prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return recurse(0, true, 2, prices);
    }
};