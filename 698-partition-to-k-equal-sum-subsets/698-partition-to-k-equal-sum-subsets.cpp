class Solution {
public:
    vector<int> vis;
    bool recurse(int index, int k, int sum, int target, vector<int> &nums, int n) {
        if(k == 1) {
            return true;
        }
        if(index >= n) {
            return false;
        }
        if(sum > target) {
            return false;
        }
        if(sum == target) {
            return recurse(0, k - 1, 0, target, nums, n);
        }
        for(int i = index; i < n; i++) {
            if(vis[i]) {
                continue;
            }
            vis[i] = true;
            if(recurse(i + 1, k, sum + nums[i], target, nums, n)) {
                return true;
            }
            vis[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vis.assign(n + 1, false);
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target % k != 0) {
            return false;
        }
        target /= k;
        return recurse(0, k, 0, target, nums, n);
    }
};