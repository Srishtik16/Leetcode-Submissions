class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int, int> m;
        for(auto x: nums) {
            m[x]++;
        }
        multiset<pair<int, int>, greater<pair<int, int>>> ms;
        for(auto x: m) {
            ms.insert({x.second, x.first});
        }
        while(ms.size() > 1) {
            auto f = *ms.begin();
            ms.erase(ms.begin());
            auto s = *ms.begin();
            ms.erase(ms.begin());
            f.first--;
            s.first--;
            if(f.first > 0) {
                ms.insert(f);
            }
            if(s.first > 0) {
                ms.insert(s);
            }
        }
        return ms.empty() ? 0: ms.begin() -> first;
    }
};