class MapSum {
public:
    map<string, int> m;
    MapSum() {
        ;
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int ans = 0;
        for(auto x: m) {
            string s = x.first;
            if(s.size() < prefix.size()) {
                continue;
            }
            else if(s.substr(0, prefix.size()) == prefix) {
                ans += x.second;
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */