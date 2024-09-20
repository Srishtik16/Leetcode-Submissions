class Solution {
public:
    vector<int> zF(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i, r = i + z[i];
            }
        }
        return z;
    }
    string shortestPalindrome(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        s = s + '$' + t;
        auto z = zF(s);
        int ans = 0;
        for(int i = n + 1; i < s.size(); i++) {
            if(z[i] == s.size() - i) {
                ans = z[i];
                break;
            }
        }
        reverse(t.begin(), t.end());
        string ss = t.substr(ans);
        reverse(ss.begin(), ss.end());
        ss += t;
        return ss;
    }
};