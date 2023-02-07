struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
        components = n;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        auto cellNo = [&](int i, int j) {
            return i * m + j;
        };
        union_find UF(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) {
                    continue;
                }
                for(int k = 0; k < n; k++) {
                    if(grid[k][j]) {
                        UF.unite(cellNo(i, j), cellNo(k, j));
                    }
                }
                for(int k = 0; k < m; k++) {
                    if(grid[i][k]) {
                        UF.unite(cellNo(i, j), cellNo(i, k));
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && UF.size[UF.find(cellNo(i, j))] > 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};