class Solution {
public:
    int recurse(int l, int r, vector<int> &nums, vector<vector<int>> &dp) {
        if(l == r) {
            return nums[r];
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int takeFirst = nums[l] - recurse(l + 1, r, nums, dp);
        int takeLast = nums[r] - recurse(l, r - 1, nums, dp);
        dp[l][r] = max(takeFirst, takeLast);
        return dp[l][r];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return recurse(0, n - 1, nums, dp) >= 0;
    }
};