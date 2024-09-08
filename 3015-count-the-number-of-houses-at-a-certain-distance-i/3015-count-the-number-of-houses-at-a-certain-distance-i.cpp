class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        x--;
        y--;
        dp[x][y] = dp[y][x] = 1;
        for(int i = 0; i < n - 1; i++) {
            dp[i][i] = 0;
            dp[i + 1][i + 1] = 0;
            dp[i][i + 1] = 1;
            dp[i + 1][i] = 1;
        }
        // Apply floyd warshall for all pairs shortest paths
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dp[i][k] != 1e9 && dp[k][j] != 1e9 && dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        dp[j][i] = dp[i][j];
                    }
                }
            }
        }
        map<int, int> cnt;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cnt[dp[i][j]]++;
            }
        }
        for(int i = 0; i < n; i++) {
            ans[i] = cnt[i + 1];
        }
        return ans;
    }
};