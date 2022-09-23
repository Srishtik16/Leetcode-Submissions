class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        auto toBinary = [&](int n) {
            string s = "";
            while(n > 0) {
                s += char(n % 2 + '0');
                n /= 2;
            }
            reverse(s.begin(), s.end());
            return s;
        };
        string s = "";
        for(int i = 1; i <= n; i++) {
            s += toBinary(i);
        }
        reverse(s.begin(), s.end());
        long long ans = 0, pw = 1;
        for(char c: s) {
            ans += (c - '0') * pw;
            ans %= MOD;
            pw *= 2;
            pw %= MOD;
        }
        return ans;
    }
};