class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        auto isVowel = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };
        vector<int> pref(n, 0), suff(n, 0);
        pref[0] = isVowel(s[0]);
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + isVowel(s[i]);
        }
        suff[n - 1] = isVowel(s[n - 1]);
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + isVowel(s[i]);
        }
        return suff[n / 2] == pref[n / 2 - 1];
    }
};