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
        DSU dsu(n * m);
        auto cellNo = [&](int i, int j) {
            return i * m + j;
        };
        auto isValid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && grid2[i][j] == 1;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] != 1) {
                    continue;
                }
                int cno = cellNo(i, j);
                for(auto x: dirs) {
                    if(isValid(i + x[0], j + x[1])) {
                        int ncno = cellNo(i + x[0], j + x[1]);
                        dsu.unite(cno, ncno);
                    }
                }
            }
        }
        map<int, int> bad;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid1[i][j] == 0 && grid2[i][j] == 1) {
                    bad[dsu.find(cellNo(i, j))] = 1;
                }
            }
        }
        set<int> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] && !bad[dsu.find(cellNo(i, j))]) {
                    ans.insert(dsu.find(cellNo(i, j)));
                }
            }
        }
        return ans.size();
    }
};