class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> prices;
    map<int, int> cnt;
    pair<int, int> dfs(int node) {
        int rootUsed = cnt[node] * prices[node] / 2;
        int rootNotUsed = cnt[node] * prices[node];
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                auto ans = dfs(x);
                rootUsed += ans.second;
                rootNotUsed += min(ans.first, ans.second);
            }
        }
        return {rootUsed, rootNotUsed};
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        // find frequency of all nodes over all trips
        // dp[node][0/1] = best result if we take / not take node, and tracking if parent was taken / not taken
        adj = vector<vector<int>>(n);
        vis = vector<bool>(n);
        prices = price;
        cnt.clear();
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        auto bfs = [&](int start, int end) {
            queue<int> q;
            q.push(start);
            vis = vector<bool>(n);
            vector<int> par(n, -1);
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                if(node == end) {
                    break;
                }
                if(vis[node]) {
                    continue;
                }
                vis[node] = true;
                for(auto x: adj[node]) {
                    if(vis[x]) {
                        continue;
                    }
                    q.push(x);
                    par[x] = node;
                }
            }
            while(end != -1) {
                cnt[end]++;
                end = par[end];
            }
        };
        for(auto &trip: trips) {
            bfs(trip[0], trip[1]);
        }
        vis = vector<bool>(n);
        auto ans = dfs(0);
        return min(ans.first, ans.second);
    }
};