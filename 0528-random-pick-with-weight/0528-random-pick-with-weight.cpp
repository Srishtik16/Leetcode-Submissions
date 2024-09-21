#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    vector<int> pref;
    Solution(vector<int>& w) {
        // [1, 3, 5]
        // [1], [2, 3, 4], [4, 5, 6, 7, 8, 9]
        int n = w.size();
        for(int i = 1; i < n; i++) {
            w[i] += w[i - 1];
        }
        pref = w;
    }
    
    int pickIndex() {
        int r = random(1, pref.back(), int);
        auto it = lower_bound(pref.begin(), pref.end(), r);
        return it - pref.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */