class Solution {
public:
    int dp[35][35][35];
    int recurse(int i, int j, int piles, int k,vector<int> &pref) {
        if((j - i + 1 - piles) % (k - 1) != 0) {
            return 1e9;
        }
        if(i == j) {
            return piles == 1 ? 0 : 1e9;
        }
        if(piles == 1) {
            return dp[i][j][piles] = recurse(i, j, k, k, pref) + pref[j] - (i > 0 ? pref[i - 1] : 0);
        }
        if(dp[i][j][piles] != -1) {
            return dp[i][j][piles];
        }
        int ans = 1e9;
        for(int mid = i; mid < j; mid += k - 1) {
            ans = min(ans, recurse(i, mid, 1, k, pref) + recurse(mid + 1, j, piles - 1, k, pref));
        }
        return dp[i][j][piles] = ans;
    } 
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<int> pref(n);
        pref[0] = stones[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + stones[i];
        }
        // dp[i][j][k] = merge [i, j] into k piles
        // dp[i][j][1] = dp[i][j][k] + (sum(i, j))
        // dp[i][j][m] = min(dp[i][mid][1] + dp[mid + 1][j][m - 1]) over all i <= mid < j; mid += k - 1 
        memset(dp, -1, sizeof(dp));
        return recurse(0, n - 1, 1, k, pref) >= 1e9 ? -1 : recurse(0, n - 1, 1, k, pref);
    }
};
