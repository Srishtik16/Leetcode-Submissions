#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    vector<int> pref;
    vector<int> w;
    Solution(vector<int>& _w) {
        w = _w;
        int sum = accumulate(w.begin(), w.end(), 0);
        int n = w.size();
        pref.resize(n);
        pref[0] = w[0];
        for(int i = 1; i < n; i++) {
            pref[i] = w[i] + pref[i - 1];
        }
    }
    
    int pickIndex() {
        int num = random(0, pref.back() - 1, int) + 1;
        // int wt = w[num];
        // int sum = accumulate(w.begin(), w.end(), 0);
        // wt = (wt * 100) / sum;
        // int wt = ;
        int l = 0, r = pref.size() - 1, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(pref[mid] == num) {
                return mid;
            }
            else if(pref[mid] > num) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */