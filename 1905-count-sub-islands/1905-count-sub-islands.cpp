class DSU {
    public:
    vector<int> parents;
    vector<int> sizes;
    int components;
    DSU(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.clear();
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
        parents[v] = u;
        sizes[u] += sizes[v];
        components--;
        return true;
    }
};
class Solution {
public:
    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        DSU dsu1(n * m), dsu2(n * m);
        auto cellNo = [&](int i, int j) {
            return i * m + j;
        };
        auto isValid1 = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && grid1[i][j] == 1;
        };
        auto isValid2 = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && grid2[i][j] == 1;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid1[i][j] != 1) {
                    continue;
                }
                int cno = cellNo(i, j);
                for(auto x: dirs) {
                    if(isValid1(i + x[0], j + x[1])) {
                        int ncno = cellNo(i + x[0], j + x[1]);
                        dsu1.unite(cno, ncno);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] != 1) {
                    continue;
                }
                int cno = cellNo(i, j);
                for(auto x: dirs) {
                    if(isValid2(i + x[0], j + x[1])) {
                        int ncno = cellNo(i + x[0], j + x[1]);
                        dsu2.unite(cno, ncno);
                    }
                }
            }
        }
        map<int, int> bad;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid1[i][j] == 0 && grid2[i][j] == 1) {
                    bad[dsu2.find(cellNo(i, j))] = 1;
                }
            }
        }
        set<int> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] && !bad[dsu2.find(cellNo(i, j))]) {
                    ans.insert(dsu2.find(cellNo(i, j)));
                }
            }
        }
        return ans.size();
    }
};