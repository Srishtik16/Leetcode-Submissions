class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) {
            return false;
        }
        vector<int> hash(26, 0);
        for(char c: s1) {
            hash[c - 'a']++;
        }
        vector<int> window(26, 0);
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            window[s2[i] - 'a']++;
        }
        bool ok = true;
        for(int i = 0; i < 26; i++) {
            ok &= hash[i] == window[i];
        }
        if(ok) {
            return ok;
        }
        for(int i = n; i < (int)s2.size(); i++) {
            window[s2[i - n] - 'a']--;
            window[s2[i] - 'a']++;
            ok = true;
            for(int i = 0; i < 26; i++) {
                ok &= hash[i] == window[i];
            }
            if(ok) {
                return ok;
            }
        }
        return false;
    }
};