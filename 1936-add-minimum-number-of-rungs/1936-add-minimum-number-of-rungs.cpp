class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        rungs.insert(rungs.begin(), 0);
        int ans = 0, n = rungs.size();
        for(int i = 1; i < n; i++) {
            ans += abs(rungs[i] - rungs[i - 1] - 1) / dist;
        }
        return ans;
    }
};