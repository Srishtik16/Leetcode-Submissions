class Info {
public:
    int index;
    string source, target;
    Info(int _index, string _source, string _target) {
        index = _index;
        source = _source;
        target = _target;
    }
    bool operator()(const Info &a, const Info &b) {
        return a.index > b.index;
    }
};
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<pair<int, pair<string, string>>> vec;
        vector<Info> val;
        for(int i = 0; i < n; i++) {
            vec.push_back(make_pair(indices[i], make_pair(sources[i], targets[i])));
        }
        sort(vec.rbegin(), vec.rend());
        for(int i = 0; i < n; i++) {
            Info info(vec[i].first, vec[i].second.first, vec[i].second.second);
            val.push_back(info);
            // vec.push_back({indices[i], {sources[i], targets[i]}});
        }
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