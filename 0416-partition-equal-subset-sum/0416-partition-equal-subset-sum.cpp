class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) {
            return false;
        }
        sum /= 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, false));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if(i == 0) {
                    dp[i][j] = false;
                }
                else if(j == 0) {
                    dp[i][j] = true;
                }
                else {
                    if(j - nums[i - 1] >= 0) {
                        dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][sum];
    }
};