class Solution {
public:
    int ans = 0;
    long long dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &values, int k) {
        vis[node] = true;
        long long sum = values[node];
        for(auto x: adj[node]) {
            if(!vis[x]) {
                sum += dfs(x, adj, vis, values, k);
            }
        }
        if(sum % k == 0) {
            ans++;
            sum = 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        ans = 0;
        vector<vector<int>> adj(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        dfs(0, adj, vis, values, k);
        return ans;
    }
};