class Solution {
public:
    int removePalindromeSub(string s) {
        auto isPalin = [&]() {
            int l = 0, r = s.size() - 1;
            while(l <= r) {
                if(s[l] != s[r]) {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        };
        return isPalin() ? 1 : 2;
    }
};