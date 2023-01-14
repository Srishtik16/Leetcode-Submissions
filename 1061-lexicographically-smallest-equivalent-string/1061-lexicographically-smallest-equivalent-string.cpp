class DSU {
public:
    vector<int> parent;
    vector<int> size;
    int components;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
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
        if(u > v) {
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DSU dsu(26);
        for(int i = 0; i < n; i++) {
            dsu.merge(s1[i] - 'a', s2[i] - 'a');
        }
        for(char &c: baseStr) {
            c = char('a' + dsu.find(c - 'a'));
        }
        return baseStr;
    }
};