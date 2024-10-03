class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modPow(long long x, long long y) {
        long long res = 1;
        while(y > 0) {
            if(y & 1) {
                res *= x;
                res %= MOD;
            }
            x *= x;
            x %= MOD;
            y /= 2;
        }
        return res % MOD;
    }
    int countGoodNumbers(long long n) {
        return (modPow(5, (n + 1) / 2) * 1LL * modPow(4, n / 2)) % MOD;
    }
};