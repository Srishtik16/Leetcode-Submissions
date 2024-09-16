class Solution {
public:
    vector<vector<vector<int>>> adj;
    vector<int> djikstra(int src) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> d(adj.size(), INT_MAX);
        d[src] = 0;
        pq.push({d[src], src});
        while(!pq.empty()) {
            int dnode = pq.top()[0], node = pq.top()[1];
            pq.pop();
            if(d[node] != dnode) {
                continue;
            }
            for(auto x: adj[node]) {
                if(d[x[0]] > d[node] + x[1]) {
                    d[x[0]] = d[node] + x[1];
                    pq.push({d[x[0]], x[0]});
                }
            }
        }
        return d;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        adj = vector<vector<vector<int>>>(n);
        for(auto &x: edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        auto f = djikstra(0);
        auto b = djikstra(n - 1);
        vector<bool> ans;
        for(auto &x: edges) {
            int from = x[0], to = x[1], wt = x[2];
            bool ok = f[from] + 0LL + wt + b[to] == f[n - 1];
            ok |= f[to] + 0LL + wt + b[from] == b[0];
            ans.push_back(ok);
        }
        return ans;
    }
};