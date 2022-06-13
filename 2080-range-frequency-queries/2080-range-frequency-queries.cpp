class RangeFreqQuery {
public:
    map<int, vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        m.clear();
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return upper_bound(m[value].begin(), m[value].end(), right) - lower_bound(m[value].begin(), m[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */