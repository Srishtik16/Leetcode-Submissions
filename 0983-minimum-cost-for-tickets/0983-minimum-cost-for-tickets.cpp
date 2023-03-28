class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        const int n = 366;
        int dp[n + 1] = {0};
        for(auto x: days) {
            dp[x] = 1;
        }
        for(int i = days[0]; i <= days.back(); i++) {
            if(dp[i]) {
                dp[i] = min({dp[max(0, i - 1)] + cost[0], dp[max(0, i - 7)] + cost[1], dp[max(i - 30, 0)] + cost[2]});
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[days.back()];
    }
};