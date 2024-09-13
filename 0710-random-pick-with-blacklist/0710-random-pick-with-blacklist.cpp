#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    map<int, int> blocked;
    int n, m;
    Solution(int _n, vector<int>& blacklist) {
        for(auto x: blacklist) {
            blocked[x] = -1;
        }
        n = _n;
        m = blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        int r = n - 1;
        for(auto x: blacklist) {
            if(x < n - m) {
                while(blocked[r] == -1) {
                    r--;
                }
                blocked[x] = r;
                r--;
            }
            else {
                break;
            }
        }
    }
    
    int pick() {
        int r = random(0, n - m - 1, int);
        if(blocked.find(r) == blocked.end()) {
            return r;
        }
        else {
            return blocked[r];
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */