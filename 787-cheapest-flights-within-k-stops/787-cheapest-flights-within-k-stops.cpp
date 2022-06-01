typedef pair<int, pair<int, int>> pii;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> vec(n);
        for(auto x: flights) {
            vec[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> minStops(n, INT_MAX);
        pq.push({0, {src, 0}});
        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            if(f.second.first == dst) {
                return f.first;
            }
            if(f.second.second > k || minStops[f.second.first] <= f.second.second) {
                continue;
            }
            minStops[f.second.first] = min(minStops[f.second.first], f.second.second);
            for(auto x: vec[f.second.first]) {
                pq.push({f.first + x.second, {x.first, f.second.second + 1}});
            }
        }
        return -1;
    }
};