class DSU {
public:
    vector<int> parent, sizes;
    int components;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sizes.assign(n, 1);
        components = n;
    }
    int find(int u) {
        return u == parent[u] ? parent[u] : parent[u] = find(parent[u]);
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) {
            return false;
        }
        if(sizes[u] < sizes[v]) {
            swap(u, v);
        }
        sizes[u] += sizes[v];
        parent[v] = u;
        components--;
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> colour;
    int level;
    void dfs(int node, int col = 0) {
        vis[node] = true;
        colour[node] = col;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x, col ^ 1);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        adj = graph;
        vis.clear();
        colour.clear();
        vis.assign(n, false);
        colour.assign(n, -1);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        int node = 0;
        for(auto x: graph) {
            for(auto y: x) {
                if(colour[y] == colour[node]) {
                    return false;
                }
            }
            node++;
        }
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Cycle of odd length is bad
        // So basically graph should be bipartite
        // If bipartite, try the diameter of the graph number of groups, grouping each level into 1
        adj = vector<vector<int>>(n);
        vis = vector<bool>(n);
        DSU dsu(n);
        for(auto &x: edges) {
            x[0]--;
            x[1]--;
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            dsu.unite(x[0], x[1]);
        }
        if(!isBipartite(adj)) {
            return -1;
        }
        auto bfs = [&](int node) {
            vis = vector<bool>(n);
            queue<int> q;
            level = 0;
            q.push(node);
            vis[node] = true;
            while(!q.empty()) {
                int qs = q.size();
                while(qs--) {
                    int node = q.front();
                    q.pop();
                    for(auto x: adj[node]) {
                        if(!vis[x]) {
                            vis[x] = true;
                            q.push(x);
                        }
                    }
                }
                level++;
            }
            return level;
        };
        map<int, int> ans;
        for(int i = 0; i < n; i++) {
            ans[dsu.find(i)] = max(ans[dsu.find(i)], bfs(i));
        }
        int res = 0;
        for(auto x: ans) {
            res += x.second;
        }
        return res;
    }
};