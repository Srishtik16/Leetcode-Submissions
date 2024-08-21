class Solution {
public:
    int robIt(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(2, 0); // for initial layer (not steal / steal)
        dp[0] = 0, dp[1] = nums[0];
        for(int i = 1; i < n; i++) {
            vector<int> new_dp(2, 0); // for current layer (not steal / steal)
            new_dp[0] = max(dp[0], dp[1]);
            new_dp[1] = dp[0] + nums[i];
            swap(dp, new_dp);
        }
        return max(dp[0], dp[1]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums.back();
        }
        return max(robIt(vector<int>(nums.begin(), nums.begin() + n - 1)), robIt(vector<int>(nums.begin() + 1, nums.end())));
    }
};