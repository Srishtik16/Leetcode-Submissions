class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        // dp[i][0/1] = move to index i via lower/higher(odd/even)move
        vector<vector<bool>> dp(n, vector<bool>(2, false));
        dp[n - 1][0] = dp[n - 1][1] = true;
        map<int, int> m;
        m[arr.back()] = n - 1;
        int ans = 1;
        for(int i = n - 2; i >= 0; i--) {
            auto hi = m.lower_bound(arr[i]);
            auto lo = m.upper_bound(arr[i]);
            if(hi != m.end()) {
                dp[i][1] = dp[hi -> second][0];
            }
            if(lo != m.begin()) {
                dp[i][0] = dp[(--lo) -> second][1];
            }
            ans += dp[i][1];
            m[arr[i]] = i;
        }
        return ans;
    }
};