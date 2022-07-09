class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool ok = is_sorted(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        ok |= is_sorted(nums.begin(), nums.end());
        return ok;
    }
};