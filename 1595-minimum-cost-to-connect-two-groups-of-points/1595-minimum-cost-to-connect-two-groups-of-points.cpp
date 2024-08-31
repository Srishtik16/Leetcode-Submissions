class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        // dp[i][mask] = best answer to process 1st i elements to mask elements
        vector<vector<int>> dp(n + 1, vector<int>((1LL << m), 1e9));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int mask = 0; mask < (1LL << m); mask++) {
                for(int j = 0; j < m; j++) {
                    if(mask & (1LL << j)) {
                        dp[i][mask] = min({dp[i][mask], dp[i][mask ^ (1 << j)] + cost[i - 1][j], dp[i - 1][mask ^ (1 << j)] + cost[i - 1][j], dp[i - 1][mask] + cost[i - 1][j]});
                    }
                }
            }
        }
        return dp[n][(1LL << m) - 1];
    }
};