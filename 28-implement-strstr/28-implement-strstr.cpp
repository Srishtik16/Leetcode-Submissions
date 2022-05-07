int MOD = 1e9 + 7;
class Solution {
public:
    int power(long long x, int n) {
        long long res = 1;
        while(n > 0) {
            if(n & 1) {
                res *= x;
                res %= MOD;
            }
            x *= x;
            x %= MOD;
            n >>= 1;
        }
        res %= MOD;
        return res;
    }
    int inv(long long x) {
        return power(x, MOD - 2);
    }
    vector<int> computeHash(string &s) {
        vector<int> pref;
        int p = 31;
        long long pw = 0, hash = 0;
        for(char c: s) {
            hash += (c - 'a' + 1) * 1LL * power(p, pw);
            hash %= MOD;
            pref.push_back(hash);
            pw++;
        }
        return pref;
    }
    int computeFullHash(string &s) {
        int p = 31;
        long long pw = 0, hash = 0;
        for(char c: s) {
            hash += (c - 'a' + 1) * 1LL * power(p, pw);
            hash %= MOD;
            pw++;
        }
        return (int)hash;
    }
    int strStr(string s, string pat) {
        if(pat.empty()) {
            return 0;
        }
        if(pat.size() > s.size()) {
            return -1;
        }
        int patHash = computeFullHash(pat);
        vector<int> h = computeHash(s);
        int l = 0, r = pat.size() - 1, n = s.size();
        while(r < n) {
            long long hashlr = 0;
            if(l == 0) {
                hashlr = (h[r] + MOD) % MOD;
                hashlr = (hashlr * inv(power(31, l)));
                hashlr %= MOD;
            }
            else {
                hashlr = (h[r] - h[l - 1] + MOD) % MOD;
                hashlr = (hashlr * inv(power(31, l)));
                hashlr %= MOD;
            }
            if(hashlr == patHash) {
                return l;
            }
            l++;
            r++;
        }
        return -1;
    }
};