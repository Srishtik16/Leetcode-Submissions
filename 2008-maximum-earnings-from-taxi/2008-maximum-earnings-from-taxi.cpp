class Solution {
public:
    long long maxTaxiEarnings(int _n, vector<vector<int>>& rides) {
        int n = rides.size();
        sort(rides.begin(), rides.end(), [&](const auto &x, const auto &y) {
            if(x[1] == y[1]) {
                return x[0] < y[0];
            }
            return x[1] < y[1];
        });
        auto getProfit = [&](vector<int> &a) {
            return a[1] - a[0] + a[2];
        };
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[rides[i][1]] = i;
        }
        vector<long long> dp(n);
        dp[0] = getProfit(rides[0]);
        for(int i = 1; i < n; i++) {
            dp[i] = getProfit(rides[i]);
            auto it = m.upper_bound(rides[i][0]);
            if(it != m.begin()) {
                advance(it, -1);
                dp[i] += dp[it -> second];
            }
            dp[i] = max(dp[i - 1], dp[i]);
        }
        return dp.back();
    }
};