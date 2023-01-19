class Solution {
public:
    void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &dp) {
        for(auto x: adj[node]) {
            if(x != par) {
                dfs(x, node, adj, dp);
                dp[node] += dp[x];
            }
        }
    }
    int countHighestScoreNodes(vector<int>& par) {
        int n = par.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            // adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        }
        vector<int> dp(n, 1);
        dfs(0, par[0], adj, dp);
        vector<long long> ans;
        for(int i = 0; i < n; i++) {
            long long product = 1;
            for(auto x: adj[i]) {
                product *= dp[x];
            }
            product *= ((n - dp[i]) == 0 ? 1 : (n - dp[i]));
            ans.push_back(product);
        }
        for(auto x: ans) {
            cout << x << " ";
        }
        cout << endl;
        int res = count(ans.begin(), ans.end(), *max_element(ans.begin(), ans.end()));
        return res;
    }
};