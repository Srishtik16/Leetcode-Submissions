class Solution {
public:
    int findPivot(vector<int> &nums, int l, int r) {
        if(r < l) {
            return -1;
        }
        if(r == l) {
            return r;
        }
        int mid = (l + r) / 2;
        if(mid < r && nums[mid] > nums[mid + 1]) {
            return mid;
        }
        if(mid > l && nums[mid] < nums[mid - 1]) {
            return mid - 1;
        }
        if(nums[l] >= nums[mid]) {
            return findPivot(nums, l, mid - 1);
        }
        return findPivot(nums, mid + 1, r);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        nums.insert(nums.begin(), -1);
        nums.push_back(INT_MAX);
        int l = 1, r = n;
        int ans = findPivot(nums, 1, n);
        l = 1, r = ans;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) {
                return mid - 1;
            }
            else if(nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        l = ans + 1, r = n;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) {
                return mid - 1;
            }
            else if(nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
};