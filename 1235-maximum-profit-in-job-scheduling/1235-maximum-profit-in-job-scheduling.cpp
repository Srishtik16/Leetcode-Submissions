class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        map<int, int> dp;
        vector<vector<int>> jobs;
        for (int i = 0; i < start.size(); i++) {
            jobs.push_back(vector<int>{start[i], end[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        int maxT = 0;
        for (auto job : jobs) {
            auto it = dp.lower_bound(job[1]);
            int pre = (it == dp.end()) ? 0 : it->second;
            maxT = max(maxT, job[2] + pre);
            dp[job[0]] = maxT;
        }
        return maxT;
    }
};