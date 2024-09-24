class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[23][401][2][2];
    int recurse(int index, int sum, bool tight1, bool tight2, string &l, string &r) {
        if(sum < 0) {
            return 0;
        }
        if(index == (int)r.size()) {
            return 1;
        }
        if(dp[index][sum][tight1][tight2] != -1) {
            return dp[index][sum][tight1][tight2];
        }
        int lb = tight1 ? l[index] - '0' : 0;
        int ub = tight2 ? r[index] - '0' : 9;
        long long ans = 0;
        for(int till = lb; till <= ub; till++) {
            ans += recurse(index + 1, sum - till, tight1 & (till == lb), tight2 & (till == ub), l, r);
            ans %= MOD;
        }
        return dp[index][sum][tight1][tight2] = ans % MOD;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        // find integers x in range [l, r]
        // such that dsum(x) lies in [left, right] 
        // we can loop for each sum in [left, right] and see how many integers
        // in range [l, r] have dsum == sum
        // use standard digit dp
        // dp(index, sum, tight) = answer till [0, r]
        // use prefix sums technique to answer the queries
        int leadingZeroes = num2.size() - num1.size();
        num1 = string(leadingZeroes,'0') + num1;
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        ans += recurse(0, max_sum, true, true, num1, num2);
        ans -= recurse(0, min_sum - 1, true, true, num1, num2);
        ans += MOD;
        ans %= MOD;
        return ans;
    }
};