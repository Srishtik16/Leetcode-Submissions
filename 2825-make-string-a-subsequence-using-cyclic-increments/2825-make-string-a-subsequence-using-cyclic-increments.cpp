class Solution {
public:
    bool canMakeSubsequence(string t, string s) {
        int ptr = 0;
        for(char c: t) {
            if(c == s[ptr]) {
                ptr++;
            }
            else if(c == 'z' && s[ptr] == 'a') {
                ptr++;
            }
            else if(char(c + 1) == s[ptr]) {
                ptr++;
            }
        }
        return ptr == s.size();
    }
};