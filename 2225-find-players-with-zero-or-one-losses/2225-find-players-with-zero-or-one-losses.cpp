struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;
template<class T>using uset=unordered_set<T,custom_hash>;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        umap<int, int> indeg;
        for(auto x: matches) {
            indeg[x[0]] = indeg[x[0]];
            indeg[x[1]]++;
        }
        for(int i = 1; i <= 1e5; i++) {
            if(indeg.find(i) != indeg.end() && indeg[i] == 0) {
                ans[0].push_back(i);
            }
            else if(indeg.find(i) != indeg.end() && indeg[i] == 1) {
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};