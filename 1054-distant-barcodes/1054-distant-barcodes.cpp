class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> m;
        for(auto x: barcodes) {
            m[x]++;
        }
        multiset<pair<int, int>, greater<pair<int, int>>> ms;
        for(auto x: m) {
            ms.insert({x.second, x.first});
        }
        vector<int> ans;
        while(ms.size() > 1) {
            auto f = *ms.begin();
            ms.erase(ms.begin());
            auto s = *ms.begin();
            ms.erase(ms.begin());
            ans.push_back(f.second);
            ans.push_back(s.second);
            f.first--;
            s.first--;
            if(f.first != 0) {
                ms.insert(f);
            }
            if(s.first != 0) {
                ms.insert(s);
            }
        }
        while(!ms.empty()) {
            ans.push_back(ms.begin() -> second);
            ms.erase(ms.begin());
        }
        return ans;
    }
};