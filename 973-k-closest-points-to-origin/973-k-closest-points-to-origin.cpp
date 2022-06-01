class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [&](int x, int y) {
            return x * x + y * y; 
        };
        priority_queue<pair<int, pair<int, int>>> pq;
        for(auto x: points) {
            if(pq.size() < k) {
                pq.push({dist(x[0], x[1]), {x[0], x[1]}});
            }
            else {
                if(pq.top().first > dist(x[0], x[1])) {
                    pq.pop();
                    pq.push({dist(x[0], x[1]), {x[0], x[1]}});
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(vector<int>{pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};