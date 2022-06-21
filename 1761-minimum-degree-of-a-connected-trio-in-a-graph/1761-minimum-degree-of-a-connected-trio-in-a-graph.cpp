class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        vector<int> deg(n, 0);
        for(auto x: edges) {
            adj[x[0] - 1][x[1] - 1] = 1;
            adj[x[1] - 1][x[0] - 1] = 1;
            deg[x[0] - 1]++;
            deg[x[1] - 1]++;
        }
        for(int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(adj[i][j] == 1 && adj[j][k] == 1 && adj[k][i] == 1) {
                        ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};