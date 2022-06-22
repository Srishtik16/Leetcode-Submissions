class Solution {
public:
    vector<vector<int>> graph;
    int dfs(int node, int mask, vector<vector<int>> &dp) {
        if(dp[node][mask] > 0) {
            return dp[node][mask];
        }
        if((mask & (mask - 1)) == 0) {
            return 0;
        }
        dp[node][mask] = INT_MAX - 1;
        for(auto x: graph[node]) {
            if(((1 << x) & mask) != 0) {
                int visited = dfs(x, mask, dp);
                int notVisited = dfs(x, mask ^ (1 << node), dp);
                dp[node][mask] = min({dp[node][mask], 1 + min(visited, notVisited)});
            }
        }
        return dp[node][mask];
    }
    int shortestPathLength(vector<vector<int>>& _graph) {
        graph = _graph;
        int n = graph.size();
        vector<vector<int>> dp(n + 1, vector<int>(1 << n));
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dfs(i, (1 << n) - 1, dp));
        }
        return ans;
    }
};