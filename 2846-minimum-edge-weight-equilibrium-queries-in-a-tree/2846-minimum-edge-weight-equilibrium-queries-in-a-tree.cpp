class Solution {
public:
    vector<vector<vector<int>>> adj;
    vector<bool> vis;
    vector<vector<int>> up;
    vector<vector<int>> depth;
    vector<int> dp;
    void dfs(int node) {
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x[0]]) {
                up[x[0]][0] = node;
                for(int i = 1; i < 20; i++) {
                    up[x[0]][i] = up[up[x[0]][i - 1]][i - 1];
                }
                for(int i = 1; i <= 26; i++) {
                    depth[x[0]][i - 1] = depth[node][i - 1] + (i == x[1]);
                }
                dp[x[0]] = dp[node] + 1;
                dfs(x[0]);
            }
        }
    }
    int getLCA(int u, int v) {
        int du = dp[u];
        int dv = dp[v];
        if(du < dv) {
            swap(du, dv);
            swap(u, v);
        }
        int k = du - dv;
        for(int i = 19; i >= 0; i--) {
            if((1 << i) & k) {
                u = up[u][i];
            }
        }
        if(u == v) {
            return u;
        }
        for(int i = 19; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // For every node we do binary lifting for each character
        adj = vector<vector<vector<int>>>(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vis = vector<bool>(n);
        up = vector<vector<int>>(n + 1, vector<int>(20));
        depth = vector<vector<int>>(n + 1, vector<int>(27));
        dp = vector<int>(n + 1);
        up[0][0] = 0;
        dfs(0);
        vector<int> ans;
        for(auto x: queries) {
            int u = x[0], v = x[1];
            int lca = getLCA(u, v);
            int mx = 0;
            for(int i = 0; i < 26; i++) {
                mx = max(mx, depth[u][i] + depth[v][i] - 2 * depth[lca][i]);
            }
            int d = dp[u] + dp[v] - 2 * dp[lca];
            ans.push_back(d - mx);
        }
        return ans;
    }
};