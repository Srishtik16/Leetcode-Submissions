class Solution {
public:
    vector<vector<int>> adj;
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        adj.clear();
        adj.resize(n);
        for(auto &edge: roads) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int val = adj[i].size() + adj[j].size();
                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                    val--;
                }
                ans = max(ans, val);
            }
        }
        return ans;
    }
};