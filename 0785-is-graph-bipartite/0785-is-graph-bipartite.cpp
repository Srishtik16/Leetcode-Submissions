class Solution {
public:
    vector<bool> vis;
    vector<int> colour;
    vector<vector<int>> adj;
    void dfs(int node, int col = 0) {
        vis[node] = true;
        colour[node] = col;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x, col ^ 1);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        adj = graph;
        vis.clear();
        colour.clear();
        vis.assign(n, false);
        colour.assign(n, -1);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        int node = 0;
        for(auto x: graph) {
            for(auto y: x) {
                if(colour[y] == colour[node]) {
                    return false;
                }
            }
            node++;
        }
        return true;
    }
};