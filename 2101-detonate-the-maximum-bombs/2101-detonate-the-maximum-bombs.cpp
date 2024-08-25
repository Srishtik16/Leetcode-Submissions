class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    int cc;
    void dfs(int node) {
        vis[node] = true;
        cc++;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        adj.clear();
        vis.clear();
        adj.resize(n);
        vis.resize(n);
        auto doIntersect = [&](auto x, auto y) {
            long long dist = abs(x[0] - y[0]) * 1LL * abs(x[0] - y[0]) + abs(x[1] - y[1]) * 1LL * abs(x[1] - y[1]);
            return dist <= x[2] * 1LL * x[2]; 
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                if(doIntersect(bombs[i], bombs[j])) {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cc = 0;
            vis.assign(n, false);
            dfs(i);
            ans = max(ans, cc);
        }
        return ans;
    }
};