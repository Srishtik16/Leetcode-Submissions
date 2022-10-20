const int MOD = 1e9 + 7;
class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        int n = a.size();
        for(auto &x: a) {
            x %= 2;
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        // dp[i][0 / 1] = number of subarrays of even / odd sum ending at i
        // dp[i][0 / 1] = (a[i] == 1 ? dp[i - 1][1 / 0] : dp[i - 1][0 / 1]) + 1
        dp[0][0] = a[0] == 0 ? 1 : 0;
        dp[0][1] = a[0] == 1 ? 1 : 0;
        for(int i = 1; i < n; i++) {
            if(a[i] == 1) {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
            }
        }
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += dp[i][1];
            sum %= MOD;
        }
        return sum;
    }
};