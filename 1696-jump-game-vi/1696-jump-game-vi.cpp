class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        multiset<int, greater<int>> ms;
        dp[0] = nums[0];
        ms.insert(nums[0]);
        for(int i = 1; i < n; i++) {
            if(ms.size() <= k) {
                dp[i] = *ms.begin() + nums[i];
                ms.insert(dp[i]);
            }
            else {
                ms.erase(ms.find(dp[i - k - 1]));
                dp[i] = *ms.begin() + nums[i];
                ms.insert(dp[i]);
            }
        }
        return dp.back();
    }
};