class Solution {
public:
    bool digitCount(string num) {
        map<int, int> m;
        for(char c: num) {
            m[c - '0']++;
        }
        bool ok = true;
        for(int i = 0; i < (int)num.size(); i++) {
            ok &= (m[i] == (num[i] - '0'));
        }
        return ok;
    }
};