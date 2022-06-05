class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 1, r = (int)nums.size(), ans = 0;
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] > nums[mid + 1]) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans < 1 ? 0 : ans - 1;
    }
};