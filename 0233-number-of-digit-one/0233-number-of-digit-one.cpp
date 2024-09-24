class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[11][2][100];
    int recurse(int index, bool tight, int count, string &r) {
        if(index == (int)r.size()) {
            return count;
        }
        if(dp[index][tight][count] != -1) {
            return dp[index][tight][count];
        }
        int ub = tight ? r[index] - '0' : 9;
        long long ans = 0;
        for(int till = 0; till <= ub; till++) {
            if(till == ub) {
                if(till == 1) {
                    ans += recurse(index + 1, tight & true, count + 1, r);
                }
                else {
                    ans += recurse(index + 1, tight & true, count, r);
                }
            }
            else {
                if(till == 1) {
                    ans += recurse(index + 1, false, count + 1, r);
                }
                else {
                    ans += recurse(index + 1, false, count, r);
                }
            }
            ans %= MOD;
        }
        return dp[index][tight][count] = ans % MOD;
    }
    int countDigitOne(int n) {
        // Count digit 1 over all ns
        // dp(index, tight) 
        // if I put 1 at index -> dp(index + 1, j, tight & (ub == j)) + 1
        // else dp(index + 1, j, tight & (ub == j))
        // Base Case -> if(index == r.size()) return 0
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return recurse(0, true, 0, s);
    }
};