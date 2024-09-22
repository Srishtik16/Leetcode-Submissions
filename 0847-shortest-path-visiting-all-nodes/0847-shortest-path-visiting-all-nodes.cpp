class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> dp;
    int dfs(int node, int mask) {
        if((mask & (mask - 1)) == 0) {
            return 0;
        }
        if(dp[node][mask] != -1) {
            return dp[node][mask];
        }
        dp[node][mask] = INT_MAX - 1;
        for(auto x: graph[node]) {
            if(((1 << x) & mask) != 0) {
                int vis = dfs(x, mask);
                int notVis = dfs(x, mask ^ (1 << node));
                dp[node][mask] = min(dp[node][mask], 1 + min(vis, notVis));
            }
        }
        return dp[node][mask];
    }
    int shortestPathLength(vector<vector<int>>& _graph) {
        graph = _graph;
        int n = graph.size();
        dp = vector<vector<int>>(n + 1, vector<int>(1 << n, -1));
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dfs(i, (1 << n) - 1));
        }
        return ans;
    }
};