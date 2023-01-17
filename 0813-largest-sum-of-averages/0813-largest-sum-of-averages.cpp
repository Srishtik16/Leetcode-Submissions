class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();
        vector<double> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        vector<double> dp(n);
        for(int i = 0; i < n; i++) {
            dp[i] = (pref.back() - pref[i]) / (n - i);
        }
        for(int k = 0; k < K - 1; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    dp[i] = max(dp[i], (pref[j] - pref[i]) / (j - i) + dp[j]);
                }
            }
        }
        return dp.front();
    }
};