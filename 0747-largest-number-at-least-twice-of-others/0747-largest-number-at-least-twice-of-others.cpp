class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = max_element(nums.begin(), nums.end()) - nums.begin();
        sort(nums.begin(), nums.end());
        int mx = nums.back(), smx = nums[(int)nums.size() - 2];
        return mx >= 2 * smx ? index : -1;
    }
};