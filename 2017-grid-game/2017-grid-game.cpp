using ll = long long;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<ll> pref(n, 0), suff(n, 0);
        pref[0] = grid[1][0];
        suff[n - 1] = grid[0][n - 1];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + grid[1][i];
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + grid[0][i];
        }
        ll ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, max(i > 0 ? pref[i - 1] : 0, i + 1 < n ? suff[i + 1] : 0));
        }
        return ans;
    }
};