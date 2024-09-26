class DSU {
public:
    vector<int> parents, sizes;
    int components;
    DSU(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.assign(n, 1);
        components = n;
    }
    int find(int u) {
        return u == parents[u] ? u : parents[u] = find(parents[u]);
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
        parents[v] = u;
        components--;
        return true;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(auto x: equations) {
            if(x[1] == '=') {
                dsu.unite(x[0] - 'a', x[3] - 'a');
            }
        }
        for(auto x: equations) {
            if(x[1] == '!') {
                if(dsu.find(x[0] - 'a') == dsu.find(x[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};