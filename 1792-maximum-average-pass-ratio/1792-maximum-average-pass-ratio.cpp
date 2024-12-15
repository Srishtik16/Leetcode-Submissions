class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        multiset<vector<double>> ms;
        auto calculateGain = [&](int passes, int total) {
            return ((double)passes + 1) / (total + 1) - ((double)passes) / total;
        };
        for(auto &x: classes) {
            ms.insert({calculateGain(x[0], x[1]), (double)x[0], (double)x[1]});
        }
        while(extraStudents--) {
            auto f = *ms.rbegin();
            ms.erase(ms.find(*ms.rbegin()));
            f[1]++;
            f[2]++;
            ms.insert({calculateGain(f[1], f[2]), f[1], f[2]});
        }
        double ans = 0.0;
        for(auto &x: ms) {
            ans += (double)x[1] / x[2];
        }
        ans /= n;
        return ans;
    }
};