class RLEIterator {
public:
    vector<pair<long long, long long>> ans;
    long long curr = 0;
    RLEIterator(vector<int>& s) {
        int n = s.size();
        for(int i = 0; i < n; i += 2) {
            ans.push_back({s[i], s[i + 1]});
        }
        for(int i = 1; i < ans.size(); i++) {
            ans[i].first += ans[i - 1].first;
        }
    }
    
    int next(int n) {
        int l = 0, r = ans.size() - 1, res = -1;
        curr += n;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(ans[mid].first >= curr) {
                res = ans[mid].second;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */