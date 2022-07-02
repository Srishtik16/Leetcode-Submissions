using ll = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        // dp[i][j] = maximum points scored from 1st i rows if I take jth column
        // from the ith row
        vector<ll> dp(m, 0);
        for(int i = 0; i < m; i++) {
            dp[i] = points[0][i];
        }
        for(int i = 1; i < n; i++) {
            vector<ll> new_dp(m, 0);
            vector<ll> pref(m), suff(m);
            pref[0] = dp[0];
            suff[m - 1] = dp[m - 1] - (m - 1);
            for(int j = 1; j < m; j++) {
                pref[j] = max(pref[j - 1], dp[j] + j);
            }
            for(int j = m - 2; j >= 0; j--) {
                suff[j] = max(suff[j + 1], dp[j] - j);
            }
            for(int j = 0; j < m; j++) {
                new_dp[j] = max(suff[j] + points[i][j] + j, pref[j] + points[i][j] - j);
            }
            dp = new_dp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};