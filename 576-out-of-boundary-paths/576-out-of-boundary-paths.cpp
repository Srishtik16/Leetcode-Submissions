const int MOD = 1e9 + 7;
class Solution {
public:
    int n, m;
    long long recurse(int i, int j, int k, long long dp[][101][101]) {
        if((i < 0 || j < 0 || i >= m || j >= n) && k >= 0) {
            return 1;
        }
        if(k < 0) {
            return 0;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        long long ansLeft = recurse(i - 1, j, k - 1, dp);
        ansLeft %= MOD;
        long long ansRight = recurse(i + 1, j, k - 1, dp);
        ansRight %= MOD;
        long long ansUp = recurse(i, j + 1, k - 1, dp);
        ansUp %= MOD;
        long long ansDown = recurse(i, j - 1, k - 1, dp);
        ansDown %= MOD;
        long long ans = ansLeft + ansRight + ansUp + ansDown;
        ans %= MOD;
        return dp[i][j][k] = ans;
    }
    int findPaths(int _m, int _n, int maxMove, int startRow, int startColumn) {
        m = _m;
        n = _n;
        long long dp[101][101][101];
        memset(dp, -1, sizeof(dp));
        return recurse(startRow, startColumn, maxMove, dp);
    }
};