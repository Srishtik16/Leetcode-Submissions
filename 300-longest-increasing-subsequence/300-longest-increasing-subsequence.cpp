class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1);
        // dp[i] = length of LIS ending at i
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};