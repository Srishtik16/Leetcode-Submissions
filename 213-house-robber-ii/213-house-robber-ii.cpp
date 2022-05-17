class Solution {
public:
    int rob1(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // dp(i, j) = maximum sum for ith prefix if we know the answer for (i-1)th prefix and
        // want to decide whether to take the ith element or not in our answer.
        dp[0][0] = 0, dp[0][1] = a[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = max({dp[i][0], dp[i - 1][1], dp[i - 1][0]});
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + a[i]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
    int rob(vector<int>& nums) {
        vector<int> a = nums;
        if(a.size() == 1) {
            return a.back();
        }
        a.erase(a.begin());
        nums.pop_back();
        return max(rob1(a), rob1(nums));
    }
};