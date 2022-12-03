class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(char c: s) {
            m[c]++;
        }
        sort(s.begin(), s.end(), [&](const auto &x, const auto &y) {
            if(m[x] == m[y]) {
                return x > y;
            }
            return m[x] > m[y];
        });
        return s;
    }
};