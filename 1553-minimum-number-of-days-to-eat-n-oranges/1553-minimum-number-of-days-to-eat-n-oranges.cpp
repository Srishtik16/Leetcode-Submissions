class Solution {
public:
    int recurse(int n, map<int, int> &dp) {
        if(n <= 1) {
            return n;
        }
        if(dp.find(n) != dp.end()) {
            return dp[n];
        }
        return dp[n] = 1 + min(n % 2 + recurse(n / 2, dp), n % 3 + recurse(n / 3, dp));
    }
    int minDays(int n) {
        map<int, int> dp;
        return recurse(n, dp);
    }
};