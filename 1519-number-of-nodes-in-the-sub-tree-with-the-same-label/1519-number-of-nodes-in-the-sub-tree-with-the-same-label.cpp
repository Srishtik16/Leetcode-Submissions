class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<vector<int>> &dp, string &labels) {
        vis[node] = true;
        dp[node][labels[node] - 'a'] = 1;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x, adj, vis, dp, labels);
                for(int i = 0; i < 26; i++) {
                    dp[node][i] += dp[x][i];
                }
            }
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, adj, vis, dp, labels);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = dp[i][labels[i] - 'a'];
        }
        return ans;
    }
};