class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dp, vector<bool> &hasApple) {
        vis[node] = true;
        dp[node] = hasApple[node];
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x, adj, vis, dp, hasApple);
                dp[node] += dp[x];
            }
        }
    }
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dp, int &ans) {
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x] && dp[x]) {
                dfs(x, adj, vis, dp, ans);
                ans++;
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> dp(n);
        dfs(0, adj, vis, dp, hasApple);
        vis.assign(n, false);
        int ans = 0;
        dfs(0, adj, vis, dp, ans);
        ans *= 2;
        return ans;
    }
};