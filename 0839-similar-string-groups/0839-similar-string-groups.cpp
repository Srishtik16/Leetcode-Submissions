class DSU {
public:
    vector<int> parent;
    vector<int> sizes;
    int components;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sizes.assign(n, 1);
        components = n;
    }
    int find(int u) {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
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
        parent[v] = u;
        sizes[u] += sizes[v];
        components--;
        return true;
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        auto check = [&](int i, int j) {
            string s = strs[i];
            string t = strs[j];
            int cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                cnt += s[i] != t[i];
            }
            return cnt <= 2;
        };
        DSU dsu(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(check(i, j)) {
                    dsu.unite(i, j);
                }
            }
        }
        return dsu.components;
    }
};