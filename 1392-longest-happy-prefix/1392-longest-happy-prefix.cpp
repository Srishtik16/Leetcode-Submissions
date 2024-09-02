class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(z[i - l], r - i);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i > r) {
                l = i;
                r = i + z[i];
            }
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(i + 1 == z[n - i - 1]) {
                ans = max(ans, i + 1);
            }
        }
        return s.substr(0, ans);
    }
};