vector<int> zFunction(string s, int n) {
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
class Solution {
public:
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
        vector<int> z = zFunction(match, n + m + 1);
        for(int i = m; i <= n + m; i++) {
            if(z[i] == m) {
                return i - m - 1;
            }
        }
        return -1;
    }
};