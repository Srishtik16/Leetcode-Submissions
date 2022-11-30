class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for(auto x: arr) {
            m[x]++;
        }
        set<int> s;
        for(auto x: m) {
            s.insert(x.second);
        }
        return s.size() == m.size();
    }
};