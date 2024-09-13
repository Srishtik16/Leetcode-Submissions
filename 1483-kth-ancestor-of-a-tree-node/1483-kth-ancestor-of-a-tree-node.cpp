class TreeAncestor {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<vector<int>> up;
    vector<int> depth;
    void dfs(int node, int dep = 0) {
        vis[node] = true;
        depth[node] = dep;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                up[x][0] = node;
                for(int i = 1; i < 20; i++) {
                    up[x][i] = up[up[x][i - 1]][i - 1];
                }
                dfs(x, dep + 1);
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        adj.resize(n);
        vis.resize(n);
        depth.resize(n);
        up = vector<vector<int>>(n + 1, vector<int>(20, 0));
        for(int i = 1; i < n; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        dfs(0);
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) {
            return -1;
        }
        for(int i = 19; i >= 0; i--) {
            if((1LL << i) & k) {
                node = up[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */