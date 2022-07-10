class DSU {
public:
    vector<int> sizes, par;
    DSU(int n) {
        sizes.assign(n + 1, 1);
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
    }
    int find_set(int node) {
        if(node != par[node]) {
            return par[node] = find_set(par[node]);
        }
        else {
            return par[node];
        }
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a != b) {
            if(sizes[a] < sizes[b]) {
                swap(a, b);
            }
            sizes[a] += sizes[b];
            sizes[b] = sizes[a];
            par[b] = a;
        }
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if((int)edges.size() != n - 1) {
            return false;
        }
        DSU dsu(n);
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if(dsu.find_set(u) == dsu.find_set(v)) {
                return false;
            }
            dsu.union_sets(u, v);
        }
        return true;
    }
};