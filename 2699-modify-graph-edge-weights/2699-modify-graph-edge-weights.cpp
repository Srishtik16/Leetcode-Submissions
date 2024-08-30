class Solution {
public:
    int dijkstra(int s, int ds, vector<vector<pair<int, int>>> &adj) {
        int n = adj.size();
        vector<long long> d(n, INT_MAX);
        d[s] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (d_v != d[v])
                continue;

            for (auto &edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    q.push({d[to], to});
                }
            }
        }
        return d[ds];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &edge: edges) {
            if(edge[2] == -1) {
                continue;
            }
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int dist = dijkstra(source, destination, adj);
        if(dist < target) {
            return vector<vector<int>>{};
        }
        bool isEqual = dist == target;
        for(auto &edge: edges) {
            if(edge[2] > 0) {
                continue;
            }
            edge[2] = isEqual ? (int)2e9 : 1;
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
            if(!isEqual) {
                int ndist = dijkstra(source, destination, adj);
                if(ndist <= target) {
                    isEqual = true;
                    edge[2] += target - ndist;
                }
            }
        }
        return isEqual ? edges : vector<vector<int>>{};
    }
};