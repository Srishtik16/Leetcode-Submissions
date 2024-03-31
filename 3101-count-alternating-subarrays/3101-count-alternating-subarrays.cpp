class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 1, ans = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                ans += cnt * (cnt + 1) / 2;
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        ans += cnt * (cnt + 1) / 2;
        return ans;
    }
};