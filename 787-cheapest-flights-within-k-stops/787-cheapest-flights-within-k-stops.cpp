class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &edge: flights) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<vector<int>> dp(n + 4, vector<int>(k + 4, INT_MAX));
        set<vector<int>> pq;
        // {current distance, node, number of stops}
        pq.insert({0, src, 0});
        dp[src][0] = 0;
        while(!pq.empty()) {
            auto u = *pq.begin();
            pq.erase(pq.begin());
            for(auto x: adj[u[1]]) {
                if(u[2] + 1 <= k + 1 && dp[x.first][u[2] + 1] == INT_MAX) {
                    dp[x.first][u[2] + 1] = min(dp[u[1]][u[2]] + x.second, dp[x.first][u[2] + 1]);
                    vector<int> v = {dp[x.first][u[2] + 1], x.first, u[2] + 1};
                    pq.insert(v);
                }
                else if(u[2] + 1 <= k + 1 && dp[x.first][u[2] + 1] > dp[u[1]][u[2]] + x.second) {
                    dp[x.first][u[2] + 1] = min(dp[u[1]][u[2]] + x.second, dp[x.first][u[2] + 1]);
                    vector<int> v = {dp[x.first][u[2] + 1], x.first, u[2] + 1};
                    pq.insert(v);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= k + 1; i++) {
            ans = min(ans, dp[dst][i]);
        }
        if(ans == INT_MAX) {
            ans = -1;
        }
        return ans;
    }
};