class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // dp[i][j] = length of the longest subsequence of 1st i element with sum j
        // dp[i][j] = (dp[i - 1][j], dp[i - 1][j - a[i -1]]) + 1
        // dp[0][0] = 0
        // dp[i][0] = 0
        // dp[0][i] = 0
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, INT_MIN));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                if(j - nums[i - 1] >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + 1);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target] <= 0 ? -1 : dp[n][target];
    }
};