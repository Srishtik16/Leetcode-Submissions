class Solution {
public:
    vector<vector<int>> dp, f;
    int compute(int l, int r, vector<int> &nums) {
        if(l > r) {
            return 0;
        }
        if(l == r) {
            return nums[l];
        }
        if(f[l][r] != -1) {
            return f[l][r];
        }
        int ans = compute(l + 1, r, nums) ^ compute(l, r - 1, nums);
        f[l][r] = ans;
        return ans;
    }
    int recurse(int l, int r, vector<int> &nums) {
        if(l > r) {
            return 0;
        }
        if(l == r) {
            return nums[l];
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int ans = max({recurse(l + 1, r, nums), recurse(l, r - 1, nums), compute(l, r, nums)});
        dp[l][r] = ans;
        return ans;
    }
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        // dp[l][r] = ans for range [l, r]
        // dp[l][r] = dp[l + 1][r], dp[l][r - 1], f[l][r]
        // f[l][r] = f[l + 1][r] ^ f[l][r - 1]
        int n = nums.size();
        dp = f = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        vector<int> ans;
        for(auto x: queries) {
            ans.push_back(recurse(x[0], x[1], nums));
        }
        return ans;
    }
};