class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, int> m;
        for(auto x: arr ) {
            m[x]++;
        }
        multiset<int> ms;
        for(auto x: m) {
            ms.insert(x.second);
        }
        while(k--) {
            int x = *ms.begin();
            ms.erase(ms.begin());
            x--;
            if(x > 0) {
                ms.insert(x);
            }
        }
        return ms.size();
    }
};