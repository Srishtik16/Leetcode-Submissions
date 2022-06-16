class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = "";
        while(n > 0) {
            s += (n % 2 == 0 ? '0' : '1');
            n /= 2;
        }
        n = s.size();
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                return false;
            }
        }
        return true;
    }
};