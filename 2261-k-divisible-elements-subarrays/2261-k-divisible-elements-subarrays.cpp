const int MOD = 1e9 + 7;
int pr = 229;
int pr1 = 211;
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
    vector<int> computeHash(vector<int> &s) {
        vector<int> pref;
        long long pw = 0, hash = 0;
        for(auto c: s) {
            hash += (c) * 1LL * power(pr, pw);
            hash %= MOD;
            pref.push_back(hash);
            pw++;
        }
        return pref;
    }
    vector<int> computeHash1(vector<int> &s) {
        vector<int> pref;
        long long pw = 0, hash = 0;
        for(auto c: s) {
            hash += (c) * 1LL * power(pr1, pw);
            hash %= MOD;
            pref.push_back(hash);
            pw++;
        }
        return pref;
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        vector<int> h = computeHash(nums);
        vector<int> h1 = computeHash1(nums);
        vector<int> pref(n, 0);
        set<pair<int, int>> uniques;
        pref[0] = nums[0] % p == 0 ? 1 : 0;
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (nums[i] % p == 0 ? 1 : 0);
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                long long hashij1 = -1, cnt = 0, hashij2 = -1;
                if(i == 0) {
                    cnt = pref[j];
                    if(cnt <= k) {
                        hashij1 = h[j];
                        hashij1 *= inv(power(pr,i));
                        hashij1 %= MOD;
                        hashij2 = h1[j];
                        hashij2 *= inv(power(pr1,i));
                        hashij2 %= MOD;
                    }
                }
                else {
                    cnt = pref[j] - pref[i - 1];
                    if(cnt <= k) {
                        hashij1 = (h[j] - h[i - 1] + MOD) % MOD;
                        hashij1 *= inv(power(pr, i));
                        hashij1 %= MOD;
                        hashij2 = (h1[j] - h1[i - 1] + MOD) % MOD;
                        hashij2 *= inv(power(pr1, i));
                        hashij2 %= MOD;
                    }
                }
                if(hashij1 != -1 && hashij2 != -1) {
                    uniques.insert({hashij1, hashij2});
                }
            }
        }
        return uniques.size();
    }
};