class Solution {
public:
    vector<bool> vis;
    void dfs(int node, vector<vector<int>> &adj) {
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x, adj);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vis.assign(n, false);
        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(source, adj);
        return vis[destination];
    }
};