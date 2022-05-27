class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // dp[i][j] = length of longest subsequence ending at i with common difference j
        // dp[i][j] = 1
        // dp[i][j] = max(dp[i][j], dp[k][j] + 1)
        int n = (int)nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1005, 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1); 
            }
        }
        int ans = 0;
        for(auto &x: dp) {
            ans = max(ans, *max_element(x.begin(), x.end()));
        }
        return ans;
    }
};