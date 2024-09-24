class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.rbegin(), jobs.rend());
        vector<int> suff(n);
        suff.back() = jobs.back()[1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], jobs[i][1]);
        }
        vector<int> id(m);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](const auto &x, const auto &y) {
            return worker[x] > worker[y];
        });
        int i = 0, j = 0;
        int cost = 0;
        while(j < m) {
            while(i < n && jobs[i][0] > worker[id[j]]) {
                i++;
            }
            cost += (i == n ? 0 : suff[i]);
            j++;
        }
        return cost;
    }
};