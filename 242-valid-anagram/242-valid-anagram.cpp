class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cs(26), ct(26);
        for(char c: s) {
            cs[c - 'a']++;
        }
        for(char c: t) {
            ct[c - 'a']++;
        }
        return cs == ct;
    }
};