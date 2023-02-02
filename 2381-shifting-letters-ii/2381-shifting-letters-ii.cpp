class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> operations(n + 1);
        for(auto x: shifts) {
            int type = x[2];
            operations[x[0]] += (type == 1 ? 1 : -1);
            operations[x[1] + 1] += (type == 1 ? -1 : 1);
        }
        for(int i = 1; i <= n; i++) {
            operations[i] += operations[i - 1];
        }
        auto calc = [&](char c, int shift) {
            int index = c - 'a';
            index += shift;
            if(index < 0) {
                index = (26 - (abs(index)%26))%26;
            }
            index %= 26;
            return char('a' + index);
        };
        int index = 0;
        for(char &c: s) {
            c = calc(c, operations[index++]);
        }
        return s;
    }
};