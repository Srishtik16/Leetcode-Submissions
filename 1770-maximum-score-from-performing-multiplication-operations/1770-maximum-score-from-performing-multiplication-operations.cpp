class Solution {
public:
    int recurse(vector<vector<int>> &dp, vector<int> &nums, vector<int> &m, int i, int start, int end) {
        if(i == (int)m.size()) {
            return 0;
        }
        if(dp[i][start] != -1) {
            return dp[i][start];
        }
        int mx1 = nums[start] * m[i] + recurse(dp, nums, m, i + 1, start + 1, end);
        int mx2 = nums[end] * m[i] + recurse(dp, nums, m, i + 1, start, end - 1);
        dp[i][start] = max(mx1, mx2);
        return dp[i][start];
    }
    int maximumScore(vector<int>& nums, vector<int>& m) {
        int n = m.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return recurse(dp, nums, m, 0, 0, (int)nums.size() - 1);
    }
};