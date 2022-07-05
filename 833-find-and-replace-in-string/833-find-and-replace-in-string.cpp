class Info {
public:
    int index;
    string source, target;
    Info(int _index, string _source, string _target) {
        index = _index;
        source = _source;
        target = _target;
    }
    bool operator < (const Info &a) {
        return this -> index > a.index;
    }
};
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<Info> val;
        for(int i = 0; i < n; i++) {
            Info info(indices[i], sources[i], targets[i]);
            val.push_back(info);
        }
        sort(val.begin(), val.end());
        for(auto x: val) {
            int i = x.index;
            string st = s.substr(i, x.source.size());
            if(st != x.source) {
                continue;
            }
            s.erase(s.begin() + i, s.begin() + i + x.source.size());
            s.insert(i, x.target);
        }
        return s;
    }
};