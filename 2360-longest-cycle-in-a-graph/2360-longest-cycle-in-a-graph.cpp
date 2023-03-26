class Solution {
public:
    map<int, int> dp;
    vector<bool> vis;
    int ans;
    void dfs(int node, vector<int> &edges) {
        vis[node] = true;
        int child = edges[node];
        if(child != -1 && !vis[child]) {
            dp[child] = dp[node] + 1;
            dfs(child, edges);
        }
        else if(child != -1 && dp.find(child) != dp.end()){
            ans = max(ans, dp[node] - dp[child] + 1);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vis.assign(n, false);
        ans = -1;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dp.clear();
                dp[i] = 1;
                dfs(i, edges);
            }
        }
        return ans;
    }
};