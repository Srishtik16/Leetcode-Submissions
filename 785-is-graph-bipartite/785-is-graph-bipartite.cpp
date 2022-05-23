class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<int> &col, int node, int dep) {
        vis[node] = true;
        cout << node << " --> " << graph[node].size() << endl;
        for(auto x: graph[node]) {
            if(!vis[x]) {
                dfs(graph, vis, col, x, (dep + 1) % 2);
                col[x] = dep;
                cout << node << " " << x << " " << col[node] << " " << col[x] << endl;
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
                    cout << currCol << " " << col[x] << " " << i << " " << x << endl;
                }
                ok &= currCol != col[x];
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
                cout << i << endl;
                col[i] = 1;
                dfs(graph, vis, col, i, 0);
            }
        }
        return check(graph, col);
    }
};