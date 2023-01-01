class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r && s[l] == s[r]) {
            while(l < r && s[l] == s[l + 1]) {
                l++;
            }
            l++;
            while(l < r && s[r] == s[r - 1]) {
                r--;
            }
            r--;
        }
        return l > r ? 0 : r - l + 1;
    }
};