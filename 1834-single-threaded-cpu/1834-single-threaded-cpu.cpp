class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> ans;
        long long currTime = 0;
        int index = 0;
        while(index < n || !pq.empty()) {
            if(pq.empty()) {
                currTime = max(currTime, (long long)tasks[index][0]);
                while(index < n && currTime >= tasks[index][0]) {
                    pq.push({tasks[index][1], tasks[index][2]});
                    index++;
                }
                pair<int, int> p = pq.top();
                pq.pop();
                currTime += p.first;
                ans.push_back(p.second);
            }
            else {
                while(index < n && currTime >= tasks[index][0]) {
                    pq.push({tasks[index][1], tasks[index][2]});
                    index++;
                }
                pair<int, int> p = pq.top();
                pq.pop();
                currTime += p.first;
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};