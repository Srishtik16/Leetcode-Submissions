class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        // dp[i] = number of subarrays with 0 sum ending at i
        long long ans = nums[0] == 0, res = ans;
        for(int i = 1; i < n; i++) {
            ans = nums[i] == 0 ? ans + 1 : 0;
            res += ans;
        }
        return res;
    }
};