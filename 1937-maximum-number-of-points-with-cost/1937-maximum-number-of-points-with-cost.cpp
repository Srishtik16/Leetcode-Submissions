using ll = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        // dp[i][j] = maximum points scored from 1st i rows if I take jth column
        // from the ith row
        vector<vector<ll>> dp(n, vector<ll>(m, 0));
        for(int i = 0; i < m; i++) {
            dp[0][i] = points[0][i];
        }
        for(int i = 1; i < n; i++) {
            vector<ll> pref(m), suff(m);
            pref[0] = dp[i - 1][0];
            suff[m - 1] = dp[i - 1][m - 1] - (m - 1);
            for(int j = 1; j < m; j++) {
                pref[j] = max(pref[j - 1], dp[i - 1][j] + j);
            }
            for(int j = m - 2; j >= 0; j--) {
                suff[j] = max(suff[j + 1], dp[i - 1][j] - j);
            }
            for(int j = 0; j < m; j++) {
                dp[i][j] = max(suff[j] + points[i][j] + j, pref[j] + points[i][j] - j);
            }
        }
        return *max_element(dp.back().begin(), dp.back().end());
    }
};