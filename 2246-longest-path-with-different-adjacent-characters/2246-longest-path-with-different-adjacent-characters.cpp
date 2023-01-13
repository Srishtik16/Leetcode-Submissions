class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, string &s, int &ans) {
        vis[node] = true;
        int mx = 0, smx = 0;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                int len = dfs(x, adj, vis, s, ans);
                if(s[node] != s[x]) {
                    if(len > smx) {
                        smx = len;
                    }
                    if(smx > mx) {
                        swap(mx, smx);
                    }
                }
                ans = max(ans, mx + smx + 1);
            }
        }
        return mx + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(int i = 1; i < n; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int ans = 1;
        dfs(0, adj, vis, s, ans);
        return ans;
    }
};