class DSU {
public:  
    vector<int> parent;
    vector<int> size;
    int components;
    DSU(int n) {
        parent.resize(n + 1, 0);
        iota(parent.begin(), parent.end() , 0);
        size.assign(n + 1, 1);
        components = n;
    }
    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) {
            return false;
        }
        if(size[u] < size[v]) {
            swap(u, v);
        }
        parent[v] = u;
        size[u] += size[v];
        components--;
        return true;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        map<int, vector<int>> nodes;
        int n = vals.size();
        for(int i = 0; i < n; i++) {
            nodes[vals[i]].push_back(i);
        }
        vector<vector<int>> adj(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        DSU dsu(n);
        int ans = 0;
        for(auto x: nodes) {
            for(auto node: x.second) {
                for(auto child: adj[node]) {
                    if(vals[node] >= vals[child]) {
                        dsu.merge(node, child);
                    }
                }
            }
            map<int, int> m;
            for(auto node: x.second) {
                m[dsu.find(node)]++;
            }
            for(auto s: m) {
                ans += (s.second * (s.second + 1) / 2);
            }
        }
        return ans;
    }
};