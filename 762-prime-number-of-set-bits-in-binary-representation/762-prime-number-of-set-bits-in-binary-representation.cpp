class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        auto isPrime = [&](int x) {
            if(x <= 1) {
                return false;
            }
            for(int i = 2; i * i <= x; i++) {
                if(x % i == 0) {
                    return false;
                }
            }
            return true;
        };
        for(int i = left; i <= right; i++) {
            int cnt = __builtin_popcount(i);
            ans += isPrime(cnt);
        }
        return ans;
    }
};