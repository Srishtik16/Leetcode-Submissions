class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end()), ans = -1;
        auto check = [&](int val) {
            int ops = maxOperations;
            for(auto x: nums) {
                ops -= ((x - 1) / val);
            }
            return ops < 0;
        };
        while(l <= r) {
            int mid = (l + r) / 2;
            if(!check(mid)) {
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