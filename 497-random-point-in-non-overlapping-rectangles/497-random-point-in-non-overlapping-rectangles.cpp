class Solution {
public:
    vector<vector<int>> rec;
    vector<int> pref;
    Solution(vector<vector<int>>& rects) {
        rec = rects;
        auto getArea = [&](vector<int> &a) {
            return (abs(a[3] - a[1]) + 1) * (abs(a[0] - a[2]) + 1);
        };
        pref.push_back(getArea(rec[0]));
        for(int i = 1; i < (int)rects.size(); i++) {
            pref.push_back(pref.back() + getArea(rec[i])); 
        }
    }
    vector<int> pick() {
        int rind = rand() % (pref.back() + 1);
        rind = lower_bound(pref.begin(), pref.end(), rind) - pref.begin();
        int rx = rec[rind][0] + rand() % (rec[rind][2] - rec[rind][0] + 1);
        int ry = rec[rind][1] + rand() % (rec[rind][3] - rec[rind][1] + 1);
        vector<int> ans = {rx, ry};
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */