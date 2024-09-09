class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        int n = s.size();
        vector<int> o(k);
        iota(o.begin(), o.end(), 0);
        sort(o.begin(), o.end(), [&](const auto &x, const auto &y) {
            return indices[x] > indices[y];
        });
        map<int, bool> used;
        for(auto x: o) {
            if(used[indices[x]]) {
                continue;
            }
            int i = indices[x];
            string ss = sources[x];
            string t = targets[x];
            int l = ss.size();
            string sss = s.substr(i, l);
            if(sss == ss) {
                s.replace(i, l, t);
                used[i] = true;
            }
        }
        return s;
    }
};