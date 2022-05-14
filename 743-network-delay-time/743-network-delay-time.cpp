const int MaxN = 1e2 + 5;
class Solution {
public:
    vector<pair<int, int>> vec[MaxN];
    vector<int> dist;
    void djikstra(int node) {
        dist[node] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node});
        while(!pq.empty()) {
            int v = pq.top().second;
            int dv = pq.top().first;
            pq.pop();
            if(dv != dist[v]) {
                continue;
            }
            for(auto x: vec[v]) {
                int u = x.first;
                int len = x.second;
                if(dist[v] + len < dist[u]) {
                    dist[u] = dist[v] + len;
                    pq.push({dist[u], u});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist.assign(n + 1, INT_MAX);
        for(int i = 0; i <= n; i++) {
            vec[i].clear();
        }
        for(auto x: times) {
            vec[x[0]].push_back({x[1], x[2]});
        }
        djikstra(k);
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            mx = max(mx, dist[i]);
        }
        return mx == INT_MAX ? -1 : mx;
    }
};