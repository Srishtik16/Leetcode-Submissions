class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums.back() >= nums.front()) {
            return nums[0];
        }
        int l = 0, r = n - 1, ans = 0;
        while(l <= r) { 
            int mid = (l + r) / 2;
            if(nums[mid] > nums[mid + 1]) {
                ans = mid + 1;
                break;
            }
            if(nums[mid - 1] > nums[mid]) {
                ans = mid;
                break;
            }
            if(nums[mid] > nums[0]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return nums[ans];
    }
};