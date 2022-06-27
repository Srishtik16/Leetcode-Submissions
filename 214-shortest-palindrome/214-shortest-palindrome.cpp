class Solution {
public:
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
    string shortestPalindrome(string s) {
        if(s.empty()) {
            return "";
        }
        int n = s.size();
        string copy = s;
        string t = s;
        reverse(t.begin(), t.end());
        s += "$";
        s += t;
        auto z = zFunction(s, 2 * n + 1);
        int ans = 0, len = 0;
        for(int i = n + 1; i <= 2 * n; i++) {
            if(z[i] == 2 * n + 1 - i) {
                ans = 2 * n - i;
                len = z[i];
                break;
            }
        }
        string st = copy.substr(ans + 1);
        reverse(st.begin(), st.end());
        st += copy;
        return st;
    }
};