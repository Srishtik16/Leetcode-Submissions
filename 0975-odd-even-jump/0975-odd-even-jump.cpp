class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        // dp[i][0] = can jump to index i as a high jump?
        // dp[i][1] = can jump to index i as a low jump?
        // dp[n - 1][0] = dp[n - 1][1] = true
        // dp[i][0] = dp[lower_bound(arr[i]) -> index][1]
        // dp[i][1] = dp[--upper_bound(arr[i]) -> index][0]
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(2, false));
        map<int, int> m;
        m[arr.back()] = n - 1;
        dp[n - 1] = {true, true};
        for(int i = n - 2; i >= 0; i--) {
            auto hi = m.lower_bound(arr[i]);
            auto lo = m.upper_bound(arr[i]);
            if(hi != m.end()) {
                dp[i][1] = dp[hi -> second][0];
            }
            if(lo != m.begin()) {
                dp[i][0] = dp[prev(lo) -> second][1];
            }
            m[arr[i]] = i;
        }
        int ans = 0;
        for(auto x: dp) {
            ans += x[1];
        }
        return ans;
    }
};