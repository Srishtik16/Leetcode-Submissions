class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0], curr = 0, ans = prev;
        for(int i = 1; i < n; i++) {
            curr = max(prev + nums[i], nums[i]);
            prev = curr;
            ans = max(ans, prev);
        }
        return ans;
    }
};