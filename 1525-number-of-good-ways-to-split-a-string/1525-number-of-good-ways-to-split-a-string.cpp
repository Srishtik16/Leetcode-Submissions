class Solution {
public:
    int numSplits(string s) {
        map<char, int> pref, suff;
        for(char c: s) {
            suff[c]++;
        }
        int ans = 0;
        for(char c: s) {
            pref[c]++;
            suff[c]--;
            if(suff[c] == 0) {
                suff.erase(c);
            }
            if(suff.size() == pref.size()) {
                ans++;
            }
        }
        return ans;
    }
};