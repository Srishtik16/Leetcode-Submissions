class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto time: times) {
            int u = time[0], v = time[1], w = time[2];
            u--;
            v--;
            adj[u].push_back({v, w});
        }
        k--;
        vector<int> d(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, k});
        d[k] = 0;
        while(!pq.empty()) {
            int dist = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();
            if(d[node] != dist) {
                continue;
            }
            for(auto child: adj[node]) {
                if(d[child[0]] > d[node] + child[1]) {
                    d[child[0]] = d[node] + child[1];
                    pq.push({d[child[0]], child[0]});
                }
            }
        }
        int mx = *max_element(d.begin(), d.end());
        return mx == INT_MAX ? -1 : mx;
    }
};