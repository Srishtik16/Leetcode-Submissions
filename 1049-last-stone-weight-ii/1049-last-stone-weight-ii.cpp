class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0LL);
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(j - stones[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j - stones[i - 1]] | dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int diff = INT_MAX;
        for(int i = 0; i <= sum / 2; i++) {
            if(dp[n][i]) {
                diff = min(diff, sum - 2 * i);
            }
        }
        return diff;
    }
};