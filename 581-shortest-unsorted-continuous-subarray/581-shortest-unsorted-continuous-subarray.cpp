class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, high = 0, low = 1, mx = INT_MIN, mn = INT_MAX;
        while(left < n) {
            if(nums[left] < mx) {
                high = left;
            }
            if(nums[right] > mn) {
                low = right;
            }
            mx = max(mx, nums[left]);
            mn = min(mn, nums[right]);
            left++;
            right--;
        }
        return high - low + 1;
    }
};