class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int mx = 0;
        for(int i = 2; i < n; i++) {
            for(int j = 1; j < i; j++) {
                int diff = arr[i] - arr[j];
                if(lower_bound(arr.begin(), arr.begin() + j, diff) - arr.begin() < j && *lower_bound(arr.begin(), arr.begin() + j, diff) == diff) {
                    dp[i][j] = max(dp[i][j], dp[j][lower_bound(arr.begin(), arr.begin() + j, diff) - arr.begin()] == 0 ? 3 : dp[j][lower_bound(arr.begin(), arr.begin() + j, diff) - arr.begin()] + 1);
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        return mx < 3 ? 0 : mx;
    }
};