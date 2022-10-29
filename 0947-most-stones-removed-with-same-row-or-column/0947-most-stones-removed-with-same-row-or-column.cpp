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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        map<int, vector<int>> mx, my;
        for(int i = 0; i < n; i++) {
            mx[stones[i][0]].push_back(i);
            my[stones[i][1]].push_back(i);
        }
        union_find UF(n);
        for(auto x: mx) {
            for(auto y: x.second) {
                UF.unite(x.second[0], y);
            }
        }
        for(auto x: my) {
            for(auto y: x.second) {
                UF.unite(x.second[0], y);
            }
        }
        return n - UF.components;
    }
};