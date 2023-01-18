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
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> a = nums;
        for(auto &x: a) {
            x = -x;
        }
        int score = -maxSubArray(a);
        int maxSum = maxSubArray(nums);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum == score ? maxSum : max(maxSum, sum - score);
    }
};