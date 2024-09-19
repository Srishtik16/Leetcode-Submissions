class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modpow(long long x, int p) {
        if(p == 0) {
            return 1;
        }
        long long res = 1;
        while(p > 0) {
            if(p & 1) {
                res *= x;
                res %= MOD;
            }
            x *= x;
            x %= MOD;
            p /= 2;
        }
        return res % MOD;
    }
    long long inv(long long x) {
        return modpow(x, MOD - 2);
    }
    int numberOfSequence(int n, vector<int>& sick) {
        sick.push_back(n);
        int prev = -1;
        vector<long long> fac(n + 2, 1), invfac(n + 2, 1);
        for(int i = 1; i <= n + 1; i++) {
            fac[i] = fac[i - 1] * i;
            fac[i] %= MOD;
        }
        invfac[n + 1] = inv(fac[n + 1]);
        for(int i = n; i >= 0; i--) {
            invfac[i] = invfac[i + 1] * (i + 1);
            invfac[i] %= MOD;
        }
        long long total = 0;
        long long ans = 1;
        for(auto x: sick) {
            int gap = x - prev - 1;
            total += gap;
            if(gap > 0) {
                ans *= invfac[gap];
                ans %= MOD;
                if(prev == -1 || x == n) {
                    prev = x;
                    continue;
                }
                ans *= modpow(2, gap - 1) % MOD;
                ans %= MOD;
            }
            prev = x;
        }
        ans *= fac[total];
        ans %= MOD;
        return ans;
    }
};