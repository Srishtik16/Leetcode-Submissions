class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp[i][0 / 1] = maximum cost from 1st i houses when not taking/taking from ith house
        vector<int> dp(2, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i < n; i++) {
            vector<int> new_dp(2, 0);
            new_dp[0] = max(dp[1], dp[0]);
            new_dp[1] = dp[0] + nums[i];
            dp.swap(new_dp);
        }
        return max(dp[0], dp[1]);
    }
};