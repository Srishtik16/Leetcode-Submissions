class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        vector<int> dp1(n), dp2(n);
        dp1[0] = (nums[0] == 1);
        for(int i = 1; i < n; i++) {
            dp1[i] = (nums[i] == 1 ? dp1[i - 1] + 1 : 0);
        }
        dp2[n - 1] = (nums[n - 1] == 1);
        for(int i = n - 2; i >= 0; i--) {
            dp2[i] = (nums[i] == 1 ? dp2[i + 1] + 1: 0);
        }
        int ans = max(dp1[n - 2], dp2[1]);
        for(int i = 1; i < n - 1; i++) {
            ans = max(ans, dp1[i - 1] + dp2[i + 1]);
        }
        return ans;
    }
};