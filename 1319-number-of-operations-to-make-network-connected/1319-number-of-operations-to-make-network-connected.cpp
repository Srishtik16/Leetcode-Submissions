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
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) {
            return false;
        }
        if(size[x] < size[y]) {
            swap(x, y);
        }
        size[x] += size[y];
        parent[y] = x;
        components--;
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int freeEdge = 0;
        for(auto x: connections) {
            if(!dsu.merge(x[0], x[1])) {
                freeEdge++;
            }
        }
        return freeEdge >= dsu.components - 1 ? dsu.components - 1 : -1;
    }
};