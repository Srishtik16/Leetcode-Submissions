class TimeMap {
public:
    map<string, vector<pair<int, string>>> m;
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = (int)m[key].size() - 1;
        string ans = "";
        while(l <= r) {
            int mid = (l + r) / 2;
            if(m[key][mid].first <= timestamp) {
                ans = m[key][mid].second;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */