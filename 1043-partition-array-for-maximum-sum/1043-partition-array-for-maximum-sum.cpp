class Solution {
public:
    int recurse(int i, vector<int> &a, int n, int k, vector<int> &dp) {
        if(i == n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int len = 0, mx = INT_MIN, ans = 0;
        for(int j = i; j < min(n, i + k); j++) {
            len++;
            mx = max(mx, a[j]);
            ans = max(ans, len * mx + recurse(j + 1, a, n, k, dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return recurse(0, arr, n, k, dp);
    }
};