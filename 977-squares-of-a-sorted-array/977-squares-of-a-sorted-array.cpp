class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1, idx = n - 1;
        while(left <= right) {
            if(nums[left] * nums[left] < nums[right] * nums[right]) {
                ans[idx--] = nums[right] * nums[right];
                right--;
            }
            else {
                ans[idx--] = nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};