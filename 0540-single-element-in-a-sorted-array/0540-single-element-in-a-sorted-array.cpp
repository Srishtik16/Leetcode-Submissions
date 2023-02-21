class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(mid < n - 1) {
                if(nums[mid] == nums[mid + 1]) {
                    mid++;
                }
            }
            if((mid + 1) % 2 == 0) {
                l = mid + 1;
            }
            else {
                ans = mid;
                r = mid - 1;
            }
        }
        return nums[ans];
    }
};