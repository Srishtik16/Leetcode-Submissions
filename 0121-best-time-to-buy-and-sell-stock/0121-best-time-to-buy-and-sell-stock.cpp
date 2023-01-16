class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, currMin = INT_MAX;
        for(auto x: prices) {
            profit = max(profit, x - currMin);
            currMin = min(currMin, x);
        }
        return profit;
    }
};