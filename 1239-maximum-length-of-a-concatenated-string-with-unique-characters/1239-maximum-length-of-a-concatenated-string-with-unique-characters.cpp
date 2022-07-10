class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), ans = 0;
        auto getMask = [&](string s) {
            int mask = 0;
            for(char c: s) {
                if((mask & (1LL << (int)(c - 'a'))) != 0) {
                    return -1;
                }
                mask |= (int)(1LL << (int)(c - 'a'));
            }
            return mask;
        };
        vector<int> masks;
        for(auto x: arr) {
            masks.push_back(getMask(x));
        }
        for(int mask = 1; mask < (1LL << n); mask++) {
            vector<int> v;
            for(int i = 0; i < n; i++) {
                if(mask & (1LL << i)) {
                    if(masks[i] != -1) {
                        v.push_back(masks[i]);
                    }
                }
            }
            if(v.empty()) {
                continue;
            }
            bool ok = true;
            int val = v[0];
            for(int i = 0; i < (int)v.size(); i++) {
                for(int j = i + 1; j < (int)v.size(); j++) {
                    if((v[i] & v[j]) != 0) {
                        ok = false;
                    }
                    else {
                        val |= v[i];
                        val |= v[j];
                    }
                }
            }
            if(ok) {
                ans = max(ans, __builtin_popcount(val));
            }
        }
        return ans;
    }
};