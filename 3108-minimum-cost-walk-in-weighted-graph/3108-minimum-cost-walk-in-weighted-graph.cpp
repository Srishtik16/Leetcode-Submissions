class DSU {
public:
    vector<int> parents, sizes;
    int components;
    map<int, int> compWeight;
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto &edge: edges) {
            dsu.unite(edge[0], edge[1]);
        }
        for(auto &edge: edges) {
            if(dsu.find(edge[0]) == dsu.find(edge[1])) {
                if(dsu.compWeight.find(dsu.find(edge[0])) == dsu.compWeight.end()) {
                    dsu.compWeight[dsu.find(edge[0])] = edge[2];
                }
                else {
                    dsu.compWeight[dsu.find(edge[0])] &= edge[2];
                }
            }
        }
        vector<int> ans;
        for(auto &q: query) {
            if(dsu.find(q[0]) == dsu.find(q[1])) {
                ans.push_back(dsu.compWeight[dsu.find(q[0])]);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};