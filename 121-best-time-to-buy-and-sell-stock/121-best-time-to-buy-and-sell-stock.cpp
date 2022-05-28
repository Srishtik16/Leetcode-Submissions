class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int buy = INT_MAX, profit = 0;
        for(auto x: a) {
            buy = min(buy, x);
            profit = max(profit, x - buy);
        }
        return profit;
    }
};