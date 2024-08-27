class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        vector<double> d(n, 0.0);
        d[start_node] = 1.0;
        while(!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(prob != d[node]) {
                continue;
            }
            for(auto x: adj[node]) {
                int child = x.first;
                double transitionProb = x.second;
                if(d[node] * transitionProb > d[child]) {
                    d[child] = d[node] * transitionProb;
                    pq.push({d[child], child});
                }
            }
        }
        return d[end_node];
    }
};