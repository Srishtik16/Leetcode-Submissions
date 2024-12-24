class Solution {
public:
    int maxD, maxN;
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, int depth) {
        vis[node] = true;
        if(maxD < depth) {
            maxD = depth;
            maxN = node;
        }
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x, adj, vis, depth + 1);
            }
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for(auto &edge: edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto &edge: edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis1(n), vis2(m);
        maxD = 0, maxN = 0;
        dfs(0, adj1, vis1, 0);
        vis1 = vector<bool>(n);
        dfs(maxN, adj1, vis1, 0);
        int d1 = maxD;
        maxD = 0, maxN = 0;
        dfs(0, adj2, vis2, 0);
        vis2 = vector<bool>(m);
        dfs(maxN, adj2, vis2, 0);
        int d2 = maxD;
        int d3 = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
        return max({d1, d2, d3});
    }
};