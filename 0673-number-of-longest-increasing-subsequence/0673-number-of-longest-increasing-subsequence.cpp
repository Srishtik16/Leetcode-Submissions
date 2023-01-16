class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        map<int, int> m;
        m[1]++;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[i] < dp[j] + 1) {
                        cnt[i] = cnt[j];
                        dp[i] = dp[j] + 1;
                    }
                    else if(dp[i] == dp[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            m[dp[i]] += cnt[i];
        }
        int lis = *max_element(dp.begin(), dp.end());
        return m[lis];
    }
};