class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<int> &col, int node, int dep) {
        vis[node] = true;
        for(auto x: graph[node]) {
            if(!vis[x]) {
                dfs(graph, vis, col, x, dep ^ 1);
                col[x] = dep;
            }
        }
    }
    bool check(vector<vector<int>> &graph, vector<int> &col) {
        int n = graph.size();
        for(int i = 0; i < n; i++) {
            int currCol = col[i];
            bool ok = true;
            for(auto x: graph[i]) {
                if(currCol == col[x]) {
                    ok &= currCol != col[x]; 
                }
            }
            if(!ok) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n + 1, false);
        vector<int> col(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                col[i] = 1;
                dfs(graph, vis, col, i, 0);
            }
        }
        return check(graph, col);
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1);
        for(auto x: dislikes) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        return isBipartite(graph);
    }
};