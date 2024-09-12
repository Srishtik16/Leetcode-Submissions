class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[100005][2][3][2];
    int recurse(int index, int l, int e, int t, int n) {
        if(index == n) {
            if(l >= 1 && t >= 1 && e >= 2) {
                return 1;
            }
            return 0;
        }
        if(dp[index][min(1, l)][min(2, e)][min(1, t)] != -1) {
            return dp[index][min(1, l)][min(2, e)][min(1, t)];
        }
        long long ans = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            if(c == 'l') {
                ans += recurse(index + 1, l + 1, e, t, n);
                ans %= MOD;
            }
            else if(c == 'e') {
                ans += recurse(index + 1, l, e + 1, t, n);
                ans %= MOD;
            }
            else if(c == 't') {
                ans += recurse(index + 1, l, e, t + 1, n);
                ans %= MOD;
            }
            else {
                ans += recurse(index + 1, l, e, t, n);
                ans %= MOD;
            }
        }
        return dp[index][min(1, l)][min(2, e)][min(1, t)] = (int)ans;
    }
    int stringCount(int n) {
        memset(dp, -1, sizeof(dp));
        return recurse(0, 0, 0, 0, n);
    }
};