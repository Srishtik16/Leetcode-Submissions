class Solution {
public:
    bool isPalindrome(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
    int recurse(string s) {
        if(s.empty()) {
            return 0;
        }
        if(isPalindrome(s)) {
            return 0;
        }
        int n = s.size();
        if(count(s.begin(), s.end(), s[0]) == 1) {
            int mid = (n + 1) / 2 - 1;
            return recurse(s.substr(1)) + mid;
        }
        int ind = 0;
        for(int i = n - 1; i >= 1; i--) {
            if(s[i] == s[0]) {
                ind = i;
                break;
            }
        }
        s.erase(s.begin());
        s.erase(s.begin() + ind - 1);
        return recurse(s) + (n - 1 - ind);
    }
    int minMovesToMakePalindrome(string s) {
        return recurse(s);
    }
};