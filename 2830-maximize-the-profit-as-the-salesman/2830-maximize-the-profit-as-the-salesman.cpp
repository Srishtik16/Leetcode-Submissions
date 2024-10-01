class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        // dp[i] = max profit for offers till i
        vector<int> dp(n, 0);
        vector<vector<vector<int>>> offersMapped(n);
        for(auto x: offers) {
            offersMapped[x[1]].push_back(x);
        }
        for(auto x: offersMapped[0]) {
            dp[0] = max(dp[0], x[2]);
        }
        for(int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            for(auto x: offersMapped[i]) {
                if(x[0] - 1 >= 0) {
                    dp[i] = max(dp[i], x[2] + dp[x[0] - 1]);
                }
                else {
                    dp[i] = max(dp[i], x[2]);
                }
            }
        }
        return dp.back();
    }
};