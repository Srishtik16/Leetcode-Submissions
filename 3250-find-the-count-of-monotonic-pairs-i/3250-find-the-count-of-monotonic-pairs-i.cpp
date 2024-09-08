class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int recurse(int index, int prev, vector<int> &nums) {
        if(index >= nums.size()) {
            return 1;
        }
        if(dp[index][prev] != -1) {
            return dp[index][prev];
        }
        int ans = 0;
        for(int i = prev; i <= nums[index]; i++) {
            int other = nums[index] - i;
            if(index > 0 && other > nums[index - 1] - prev) {
                continue;
            }
            ans += recurse(index + 1, i, nums);
            ans %= MOD;
        }
        return dp[index][prev] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        // f(ind, prev) = prev index had prev, so number of ways for ith index
        // f(ind + 1, try values which are valid with prev)
        dp = vector<vector<int>>(2005, vector<int>(55, -1));
        return recurse(0, 0, nums);
    }
};