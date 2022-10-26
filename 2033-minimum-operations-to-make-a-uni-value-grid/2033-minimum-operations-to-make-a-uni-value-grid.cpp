class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int k) {
        vector<int> a;
        for(auto x: grid) {
            for(auto y: x) {
                a.push_back(y);
            }
        }
        sort(a.begin(), a.end());
        int n = a.size();
        int med = a[n / 2];
        bool ok = true;
        int moves = 0;
        for(auto x: grid) {
            for(auto y: x) {
                if(abs(y - med) % k == 0) {
                    moves += abs(y - med) / k;
                }
                else {
                    ok = false;
                }
            }
        }
        return ok ? moves : -1;
    }
};