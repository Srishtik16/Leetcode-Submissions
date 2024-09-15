class Solution {
public:
    int solve(vector<int> &nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                if(i - 2 >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + nums[i - 1]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], nums[i - 1]);
                }
            }
        }
        return dp[n][k];
    }
    int maxSizeSlices(vector<int>& slices) {
        // House Robber 2 style approach
        // take 1st exclude last or take last exclude first
        // dp[i][j] = answer for 1st i elements if we take j non adjacent out of them
        // Now we have a take/not take style dp
        int n = slices.size();
        vector<int> c = slices;
        slices.pop_back();
        c.erase(c.begin());
        return max(solve(c, n / 3), solve(slices, n / 3));
    }
};