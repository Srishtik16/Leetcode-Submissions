const int INF = 1e9 + 5;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, INF));
        for(auto x: edges) {
            adj[x[0]][x[1]] = x[2];
            adj[x[0]][x[0]] = 0;
            adj[x[1]][x[1]] = 0;
        }
        vector<vector<int>> d = adj;
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    d[j][i] = d[i][j];
                }
            }
        }
        int ans = INT_MAX, ansNode = 0;
        for(int i = 0; i < n; i++) {
            int nodes = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                if(d[i][j] != INF) {
                    if(d[i][j] <= distanceThreshold) {
                        nodes++;
                    }
                }
            }
            if(ans >= nodes) {
                ans = nodes;
                ansNode = max(ansNode, i);
            }
        }
        return ansNode;
    }
};