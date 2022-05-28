class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size(), ans = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i - 1] < prices[i]) {
                ans += abs(prices[i - 1] - prices[i]);
            }
        }
        return ans;
    }
};