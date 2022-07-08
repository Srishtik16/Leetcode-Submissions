class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> dp;
        for(auto x: arr) {
            dp[x] = max(dp[x], 1 + dp[x - difference]);
        }
        int ans = 0;
        for(auto x: dp) {
            ans = max(ans, x.second);
        }
        return ans;
    }
};