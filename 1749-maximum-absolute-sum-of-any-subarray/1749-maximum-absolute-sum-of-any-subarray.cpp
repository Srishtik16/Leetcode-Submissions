class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n), dp2(n);
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        for(int i = 1; i < n; i++) {
            dp1[i] = max(dp1[i - 1] + nums[i], nums[i]);
            dp2[i] = min(dp2[i - 1] + nums[i], nums[i]);
        }
        return max(abs(*min_element(dp2.begin(), dp2.end())), abs(*max_element(dp1.begin(), dp1.end())));
    }
};