class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = 0;
            for(int i = 0; i < mid; i++) {
                sum += nums[i];
            }
            int maxSum = sum;
            for(int i = mid; i < n; i++) {
                sum -= nums[i - mid];
                sum += nums[i];
                maxSum = max(maxSum, sum);
            }
            if(maxSum >= target) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};