class Solution {
public:
    char repeatedCharacter(string s) {
        map<char, int> m;
        for(char c: s) {
            if(m.find(c) != m.end()) {
                return c;
            }
            m[c]++;
        }
        return '8';
    }
};