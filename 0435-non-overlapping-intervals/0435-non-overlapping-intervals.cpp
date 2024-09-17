class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto &x, const auto &y) {
            return x[1] < y[1];
        });
        int prev = 0;
        int ans = 0;
        for(int i = 1; i < (int)intervals.size();i++) {
            while(i < (int)intervals.size() && intervals[i][0] < intervals[prev][1]) {
                i++;
                ans++;
            }
            prev = i;
        }
        return ans;
    }
};