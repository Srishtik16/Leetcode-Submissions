class Solution {
public:
    vector<int> tin, low;
    int timer;
    void dfs(int node, int par, vector<vector<int>> &vec, vector<bool> &vis, vector<vector<int>> &bridges) {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for(auto x: vec[node]) {
            if(x == par) {
                continue;
            }
            if(!vis[x]) {
                dfs(x, node, vec, vis, bridges);
                low[node] = min(low[node], low[x]);
                if(low[x] > tin[node]) {
                    bridges.push_back({node, x});
                }
            }
            else {
                low[node] = min(low[node], tin[x]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> vec(n + 1);
        vector<bool> vis(n + 1, false);
        tin.assign(n + 1, -1);
        low.assign(n + 1, -1);
        timer = 0;
        vector<vector<int>> bridges;
        for(auto x: connections) {
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);
        }
        dfs(0, -1, vec, vis, bridges);
        return bridges;
    }
};