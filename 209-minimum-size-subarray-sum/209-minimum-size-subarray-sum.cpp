class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, ans = INT_MAX, sum = 0;
        while(l <= r && r < n) {
            sum += nums[r];
            while(sum >= target) {
                sum -= nums[l];
                ans = min(ans, r - l + 1);
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};