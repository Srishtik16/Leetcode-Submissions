class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j < i && nums[j] + k < nums[i] - k) {
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};