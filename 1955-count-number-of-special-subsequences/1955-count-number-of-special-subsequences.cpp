class Solution {
public:
    const int MOD = 1e9 + 7;
    int countSpecialSubsequences(vector<int>& nums) {
        vector<long long> dp(3, 0);
        for(auto x: nums) {
            dp[x] = (dp[x] + dp[x]) % MOD + (x > 0 ? dp[x - 1] : 1) % MOD;
        }
        return dp.back() % MOD;
    }
};