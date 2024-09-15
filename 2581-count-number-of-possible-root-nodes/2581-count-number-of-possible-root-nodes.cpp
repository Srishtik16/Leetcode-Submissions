class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    unordered_map<int, unordered_map<int, int>> g;
    int roots, total, k;
    void dfs(int node) {
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                total += g[node][x];
                dfs(x);
            }
        }
    }
    void dfs(int node, int tot) {
        vis[node] = true;
        if(tot >= k) {
            roots++;
        }
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x, tot - g[node][x] + g[x][node]);
            }
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int _k) {
        int n = edges.size() + 1;
        adj.clear();
        adj.resize(n);
        vis = vector<bool>(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(auto x: guesses) {
            g[x[0]][x[1]] = 1;
        }
        k = _k;
        roots = 0, total = 0;
        dfs(0);
        vis = vector<bool>(n);
        dfs(0, total);
        return roots;
    }
};