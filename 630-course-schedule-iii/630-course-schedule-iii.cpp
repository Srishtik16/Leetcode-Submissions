class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](const auto &x, const auto &y) {
            return x[1] < y[1];
        });
        priority_queue<int> pq;
        int time = 0, ans = 0;
        for(auto x: courses) {
            if(time + x[0] <= x[1]) {
                time += x[0];
                ans++;
                pq.push(x[0]);
            }
            else {
                if(!pq.empty() && pq.top() > x[0]) {
                    time += x[0] - pq.top();
                    pq.pop();
                    pq.push(x[0]);
                }
            }
        }
        return ans;
    }
};