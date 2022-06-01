class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int p1 = 1, p2 = 1, p3 = 1;
        for(int i = 2; i <= n; i++) {
            int f1 = dp[p1] * 2;
            int f2 = dp[p2] * 3;
            int f3 = dp[p3] * 5;
            int mn = min({f1, f2, f3});
            dp[i] = mn;
            if(mn == f1) {
                p1++;
            }
            if(mn == f2) {
                p2++;
            }
            if(mn == f3) {
                p3++;
            }
        }
        return dp.back();
    }
};