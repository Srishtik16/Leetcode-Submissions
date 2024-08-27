class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i] != t[j]) {
                    int l = 1, r = 1;
                    while(i - l >= 0 && j - l >= 0 && s[i - l] == t[j - l]) {
                        l++;
                    }
                    while(i + r < n && j + r < m && s[i + r] == t[j + r]) {
                        r++;
                    }
                    ans += l * r;
                }
            }
        }
        return ans;
    }
};
