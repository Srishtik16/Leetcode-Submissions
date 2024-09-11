class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        // dp[i][j] = number of playlists with i songs with j unique songs
        // If I add a new song -> dp[i - 1][j -1] * (n - (j - 1)) (n - j + 1 choices)
        // If I add an old song -> dp[i - 1][j] * (j - k) (last k out of j can't be played)
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= goal; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) + dp[i - 1][j] * max(j - k, 0);
                dp[i][j] %= MOD;
            }
        }
        return dp[goal][n];
    }
};