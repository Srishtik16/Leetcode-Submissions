class Solution {
public:
    long long mxd;
    int mxn;
    vector<long long> dist;
    void dfs(int node, int par, long long d, vector<vector<int>> &adj, vector<int> &price) {
        if(mxd < d) {
            mxd = d;
            mxn = node;
        }
        for(auto x: adj[node]) {
            if(x != par) {
                dfs(x, node, d + price[x], adj, price);
            }
        }
    }
    void distanceDfs(int node, int par, long long d, vector<vector<int>> &adj, vector<int> &price) {
        dist[node] = max<long long>(dist[node], d);
        for(auto x: adj[node]) {
            if(x != par) {
                distanceDfs(x, node, d + price[x], adj, price);
            }
        }
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        mxd = 0, mxn = 0;
        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0, -1, price[0], adj, price);
        mxd = 0;
        int node1 = mxn;
        dfs(mxn, -1, price[mxn], adj, price);
        int node2 = mxn;
        dist.assign(n, 0);
        distanceDfs(node1, -1, price[node1], adj, price);
        vector<long long> d1 = dist;
        dist.assign(n, 0);
        distanceDfs(node2, -1, price[node2], adj, price);
        vector<long long> d2 = dist;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, abs(max(d1[i], d2[i]) - price[i]));
        }
        return ans;
    }
};