class Solution {
public:
    vector<int> getLPS(string s, int n) {
        vector<int> lps(n);
        int i = 1;
        int len = 0;
        while(i < n) {
            if(s[i] == s[len]) {
                lps[i++] = ++len;
            }
            else {
                if(len == 0) {
                    lps[i++] = 0;
                }
                else {
                    len = lps[len - 1];
                }
            }
        }
        return lps;
    }
    int strStr(string s, string pat) {
        if(pat.empty()) {
            return 0;
        }
        if(pat.size() > s.size()) {
            return -1;
        }
        string match = pat + '$' + s;
        int n = s.size();
        int m = pat.size();
        vector<int> lps = getLPS(match, n + m + 1);
        for(int i = m; i <= n + m; i++) {
            if(lps[i] == m) {
                return i - m - 1 - m + 1;
            }
        }
        return -1;
    }
};