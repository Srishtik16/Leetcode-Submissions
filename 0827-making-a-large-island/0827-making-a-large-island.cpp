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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        union_find UF(n * n);
        auto cellNo = [&](int i, int j) {
            return i * n + j;
        };
        auto isValid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < n && cellNo(i, j) >= 0 && cellNo(i, j) < n * n;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    if(isValid(i + 1, j) && grid[i + 1][j] == 1) {
                        UF.unite(cellNo(i, j), cellNo(i + 1, j));
                    }
                    if(isValid(i - 1, j) && grid[i - 1][j] == 1) {
                        UF.unite(cellNo(i, j), cellNo(i - 1, j));
                    }
                    if(isValid(i, j + 1) && grid[i][j + 1] == 1) {
                        UF.unite(cellNo(i, j), cellNo(i, j + 1));
                    }
                    if(isValid(i, j - 1) && grid[i][j - 1] == 1) {
                        UF.unite(cellNo(i, j), cellNo(i, j - 1));
                    }
                }
            }
        }
        int best = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    int island = 1;
                    set<int> s;
                    if(isValid(i + 1, j) && grid[i + 1][j] == 1) {
                        s.insert(UF.find(cellNo(i + 1, j)));
                    }
                    if(isValid(i - 1, j) && grid[i - 1][j] == 1) {
                        s.insert(UF.find(cellNo(i - 1, j)));
                    }
                    if(isValid(i, j + 1) && grid[i][j + 1] == 1) {
                        s.insert(UF.find(cellNo(i, j + 1)));
                    }
                    if(isValid(i, j - 1) && grid[i][j - 1] == 1) {
                        s.insert(UF.find(cellNo(i, j - 1)));
                    }
                    for(auto x: s) {
                        island += UF.size[x];
                    }
                    best = max(best, island);
                }
            }
        }
        if(best == -1) {
            best = n * n;
        }
        return best;
    }
};