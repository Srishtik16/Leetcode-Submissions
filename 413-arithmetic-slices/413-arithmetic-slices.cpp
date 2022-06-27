class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) {
            return 0;
        }
        // dp[i] = numbers of arithmetic subarrays ending at i
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < n; i++) {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = 1;
            }
        }
        int ans = 1;
        for(auto x: dp) {
            ans += x - 1;
        }
        return ans;
    }
};