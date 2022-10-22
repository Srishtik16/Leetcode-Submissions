class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        // dp[i] = number of subarrays with 0 sum ending at i
        vector<long long> dp(n, 0);
        dp[0] = nums[0] == 0;
        for(int i = 1; i < n; i++) {
            dp[i] = nums[i] == 0 ? dp[i - 1] + 1 : 0;
        }
        return accumulate(dp.begin(), dp.end(), 0LL);
    }
};