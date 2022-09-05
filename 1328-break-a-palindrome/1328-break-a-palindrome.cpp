class Solution {
public:
    bool isPal(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
    string breakPalindrome(string s) {
        int n = s.size();
        string ans(n, 'z');
        for(int i = 0; i < n; i++) {
            for(char c = 'a'; c <= 'z'; c++) {
                if(c == s[i]) {
                    continue;
                }
                string ss = s;
                ss[i] = c;
                if(!isPal(ss)) {
                    if(ans > ss) {
                        ans = ss;
                    }
                }
                ss = s;
            }
        }
        if(isPal(ans)) {
            ans = "";
        }
        return ans;
        }
};