class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 1; i < (int)nums.size(); i++) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};