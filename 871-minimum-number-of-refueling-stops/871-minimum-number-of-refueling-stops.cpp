class Solution {
public:
    int minRefuelStops(int target, int cap, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int prev = 0, ans = 0;
        stations.push_back(vector<int>{target, INT_MAX});
        for(auto x: stations) {
            int pos = x[0];
            int amt = x[1];
            cap -= pos - prev;
            while(!pq.empty() && cap < 0) {
                cap += pq.top();
                pq.pop();
                ans++;
            }
            pq.push(amt);
            prev = pos;
            if(cap < 0) {
                return -1;
            }
        }
        return ans;
    }
};