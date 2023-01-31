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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [&](const auto &x, const auto &y) {
            return x[2] < y[2];
        });
        int ind = 0;
        for(auto &x: queries) {
            x.push_back(ind++);
        }
        sort(queries.begin(), queries.end(), [&](const auto &x, const auto &y) {
            return x[2] < y[2];
        });
        union_find UF(n);
        vector<bool> ans(size(queries), false);
        ind = 0;
        for(auto x: queries) {
            while(ind < size(edgeList) && edgeList[ind][2] < x[2]) {
                UF.unite(edgeList[ind][0], edgeList[ind][1]);
                ind++;
            }
            if(UF.find(x[0]) == UF.find(x[1])) {
                ans[x[3]] = true;
            }
        }
        return ans;
    }
};