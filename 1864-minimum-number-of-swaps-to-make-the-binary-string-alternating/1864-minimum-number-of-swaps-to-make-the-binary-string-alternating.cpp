class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int c0 = count(s.begin(), s.end(), '0');
        int c1 = n - c0;
        if(min(c0, c1) != n / 2) {
            return -1;
        }
        string s1 = "", s2 = "";
        bool parity = true;
        for(int i = 0; i < n; i++) {
            if(parity) {
                s1 += '0';
                s2 += '1';
            }
            else {
                s1 += '1';
                s2 += '0';
            }
            parity ^= 1;
        }
        auto countMismatch = [&](string s, string t) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += s[i] != t[i];
            }
            return cnt % 2 == 0 ? cnt / 2 : INT_MAX;
        };
        int mx = min(countMismatch(s, s1), countMismatch(s, s2)); 
        return mx == INT_MAX ? -1 : mx;
    }
};

// 11000
// 10101
// 01010
// 01010