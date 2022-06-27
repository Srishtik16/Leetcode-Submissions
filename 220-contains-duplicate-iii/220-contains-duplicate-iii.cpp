class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        multiset<long long> ms;
        for(int i = 0; i < n; i++) {
            if(i > k) {
                ms.erase(ms.find(1LL * nums[i - k - 1]));
            }
            auto it = ms.lower_bound(1LL * nums[i] - t);
            if(it != ms.end() && *it <= 1LL * nums[i] + t) {
                return true;
            }
            ms.insert(nums[i]);
        }
        return false;
    }
};