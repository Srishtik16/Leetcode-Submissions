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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        union_find UF(n);
        for(auto x: pairs) {
            UF.unite(x[0], x[1]);
        }
        map<int, int> compress;
        int index = 0;
        set<int> p;
        for(int i = 0; i < n; i++) {
            p.insert(UF.find(i));
        }
        for(auto x: p) {
            compress[x] = index++;
        }
        vector<string> sorted(UF.components);
        for(int i = 0; i < n; i++) {
            sorted[compress[UF.find(i)]] += s[i];
        }
        for(auto &x: sorted) {
            sort(x.begin(), x.end());
        }
        for(int i = n - 1; i >= 0; i--) {
            s[i] = sorted[compress[UF.find(i)]].back();
            sorted[compress[UF.find(i)]].pop_back();
        }
        return s;
    }
};