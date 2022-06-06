class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;
    ll power(ll x, ll y, ll p)  
    {  
        ll res = 1;     // Initialize result  

        x = x % p; // Update x if it is more than or  
                    // equal to p 

        if (x == 0) return 0; // In case x is divisible by p; 

        while (y > 0)  
        {  
            // If y is odd, multiply x with result  
            if (y & 1)  
                res = (res * x) % p;

            // y must be even now  
            y = y>>1LL; // y = y/2  
            x = (x*x) % p;  
        }  
        return res;  
    }  
    int findTargetSumWays(vector<int>& a, int d) {
        int n = a.size();
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        if((sum + d) < 0 || (sum + d) % 2 != 0) {
            return 0;
        }
        vector<long long> pref(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (a[i - 1] == 0);
        }
        sum *= 2;
        vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
        sum /= 2;
        for(int i = 0; i <= n; i++) {
            dp[i][0] = power(2, pref[i], MOD);
        }
        for(int i = 0; i <= sum; i++) {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(j - a[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
                    dp[i][j] %= MOD;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
            }
        }
        return (dp[n][(sum + d) / 2]);
    }
};