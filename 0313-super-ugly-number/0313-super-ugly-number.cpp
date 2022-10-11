class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int l = primes.size();
        vector<int> indexes(l, 1);
        for(int i = 2; i <= n; i++) {
            vector<long long> next(l);
            for(int j = 0; j < l; j++) {
                next[j] = dp[indexes[j]] * 1LL * primes[j];
            }
            int index = min_element(next.begin(), next.end()) - next.begin();
            dp[i] = next[index];
            for(int j = 0; j < l; j++) {
                if(next[index] == next[j]) {
                    indexes[j]++;
                }
            }
        }
        return dp.back();
    }
};