class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        for(auto x: arr) {
            m[x]++;
        }
        multiset<pair<int, int>, greater<pair<int, int>>> ms;
        for(auto x: m) {
            ms.insert({x.second, x.first});
        }
        int n = arr.size();
        int sz = n;
        int cnt = 0;
        while(!ms.empty() && sz > n / 2) {
            auto it = *ms.begin();
            ms.erase(ms.begin());
            sz -= it.first;
            cnt++;
        }
        return cnt;
    }
};