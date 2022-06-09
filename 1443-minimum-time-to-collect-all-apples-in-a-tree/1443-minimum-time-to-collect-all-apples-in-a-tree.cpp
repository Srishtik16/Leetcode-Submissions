class Solution {
public:
    void dfs(int node, vector<int> vec[], vector<bool> &has, vector<bool> &vis, vector<int> &dp) {
        vis[node] = true;
        dp[node] = has[node];
        for(auto x: vec[node]) {
            if(!vis[x]) {
                dfs(x, vec, has, vis, dp);
                dp[node] += dp[x];
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> vec[n + 1];
        for(auto x: edges) {
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);
        }
        vector<int> dp(n + 1, 0);
        vector<bool> vis(n + 1, false);
        dfs(0, vec, hasApple, vis, dp);
        int ans = 0;
        for(int i = 1; i < n; i++) {
            ans += dp[i] ? 2 : 0;
        }
        return ans;
    }
};