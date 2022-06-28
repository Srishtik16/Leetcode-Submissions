class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int i = 0, ans = 0;
        for(int day = 0; day <= 1e5; day++) {
            while(i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
            while(!pq.empty() && pq.top() < day + 1) {
                pq.pop();
            }
            if(pq.empty() && i >= n) {
                break;
            }
        }
        return ans;
    }
};