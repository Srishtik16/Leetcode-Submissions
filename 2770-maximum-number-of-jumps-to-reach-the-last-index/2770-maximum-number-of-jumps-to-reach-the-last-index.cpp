class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // dp[i] = max steps to reach i
        // dp[0] = 0
        // dp[i] = max(dp[j] + 1) if abs(nums[j] - nums[i]) <= target
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(abs(nums[i] - nums[j]) <= target && dp[j] != -1) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }
        return dp.back();
    }
};