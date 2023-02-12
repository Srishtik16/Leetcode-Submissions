class Solution {
public:
    vector<long long> dp;
    vector<vector<int>> adj;
    vector<bool> vis;
    void dfs(int node) {
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x);
                dp[node] += dp[x];
            }
        }
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        dp.assign(n + 1, 1);
        adj.clear();
        adj.resize(n + 1);
        vis.assign(n + 1, false);
        for(int i = 0; i < n; i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        dfs(0);
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += (dp[i] + seats - 1) / seats;
        }
        return ans;
    }
};