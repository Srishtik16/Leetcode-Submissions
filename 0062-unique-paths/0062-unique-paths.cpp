class Solution {
public:
    int uniquePaths(int m, int n) {
        using ll = long long;
        ll num = n + m - 2, den = 1;
        ll ans = 1;
        for(int i = 1; i < min(n, m); i++) {
            ans *= num;
            ans /= den;
            num--;
            den++;
        }
        return ans;
    }
};