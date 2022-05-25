class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), [&](const auto &x, const auto &y) {
            if(x[0] == y[0]) {
                return x[1] > y[1];
            }
            return x[0] < y[0];
        });
        vector<int> lis;
        for(int i = 0; i < n; i++) {
            auto ind = lower_bound(lis.begin(), lis.end(), a[i][1]) - lis.begin();
            if(ind >= (int)lis.size()) {
                lis.push_back(a[i][1]);
            }
            else {
                lis[ind] = a[i][1];
            }
        }
        return lis.size();
    }
};