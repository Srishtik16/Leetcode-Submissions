int MOD = 1e9 + 9;
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
        int p = 29;
        long long pw = 0, hash = 0;
        for(char c: s) {
            hash += (c - 'a' + 1) * 1LL * power(p, pw);
            hash %= MOD;
            pref.push_back(hash);
            pw++;
        }
        return pref;
    }
    int computeFullHash(string s) {
        int p = 29;
        long long pw = 0, hash = 0;
        for(char c: s) {
            hash += (c - 'a' + 1) * 1LL * power(p, pw);
            hash %= MOD;
            pw++;
        }
        return (int)hash;
    }
    int substringHash(vector<int> &h, int l, int r) {
        int p = 29;
        if(l > r) {
            return 0;
        }
        long long hashlr = 0;
        if(l == 0) {
            hashlr = (h[r] + MOD) % MOD;
            hashlr = (hashlr * inv(power(p, l)));
            hashlr %= MOD;
        }
        else {
            hashlr = (h[r] - h[l - 1] + MOD) % MOD;
            hashlr = (hashlr * inv(power(p, l)));
            hashlr %= MOD;
        }
        return hashlr;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n = startWords.size();
        unordered_map<int, string> hashStart;
        for(int i = 0; i < n; i++) {
            string s = startWords[i];
            sort(startWords[i].begin(), startWords[i].end());
            hashStart[computeFullHash(startWords[i])] = s;
        }
        int ans = 0;
        for(auto x: targetWords) {
            sort(x.begin(), x.end());
            vector<int> hash = computeHash(x);
            int l = x.size();
            for(int i = 0; i < l; i++) {
                long long hashPref = substringHash(hash, 0, i - 1);
                long long hashSuff = substringHash(hash, i + 1, l - 1);
                long long suffLen = max(0, l - 1 - i - 1 + 1);
                hashSuff *= power(29, i);
                hashSuff %= MOD;
                hashPref += hashSuff;
                hashPref %= MOD;
                if(hashStart.find(hashPref) != hashStart.end()) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};