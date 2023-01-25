class Solution {
public:
    vector<vector<int>> adj;
    vector<int> bfs(int node, int n) {
        vector<bool> vis(n, false);
        vector<int> d(n, INT_MAX);
        queue<int> q;
        d[node] = 0;
        vis[node] = true;
        q.push(node);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto x: adj[u]) {
                if(!vis[x]) {
                    d[x] = d[u] + 1;
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        return d;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        adj.clear();
        adj.resize(n + 1);
        for(int i = 0; i < n; i++) {
            if(edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> d1 = bfs(node1, n);
        vector<int> d2 = bfs(node2, n);
        int ans = INT_MAX, node = -1;
        for(int i = 0; i < n; i++) {
            if(max(d1[i], d2[i]) < ans) {
                ans = max(d1[i], d2[i]);
                node = i;
            }
        }
        return node;
    }
};