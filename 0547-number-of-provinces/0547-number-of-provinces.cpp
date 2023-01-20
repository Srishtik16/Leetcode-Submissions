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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) {
                    dsu.merge(i, j);
                }
            }
        }
        return dsu.components;
    }
};