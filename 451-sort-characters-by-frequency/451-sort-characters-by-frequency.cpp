class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(char c: s) {
            m[c]++;
        }
        s.clear();
        vector<pair<int, char>> v;
        for(auto x: m) {
            v.push_back({x.second, x.first});
        }
        sort(v.rbegin(), v.rend());
        s.clear();
        for(auto x: v) {
            s += string(x.first, x.second);
        }
        return s;
    }
};