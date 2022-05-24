class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0LL);
        vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1));
        // dp[i][j] = can I make sum of j with 1st i elements of the array?
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for(int j = 0; j <= sum; j++) {
            dp[0][j] = false;
        }
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(j - nums[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if(sum % 2 != 0) {
            return false;
        }
        return dp[n][sum / 2];
    }
};