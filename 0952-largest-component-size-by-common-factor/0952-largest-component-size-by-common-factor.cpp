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
        if(size[u] < size[v]) {
            swap(u, v);
        }
        parent[v] = u;
        size[u] += size[v];
        components--;
        return true;
    }
};
const int MaxN = 1e5 + 5;
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        DSU dsu(MaxN);
        for(auto x: nums) {
            for(int j = 2; j * j <= x; j++) {
                if(x % j == 0) {
                    dsu.merge(x, x / j);
                    dsu.merge(x, j);
                }
            }
        }
        map<int, int> m;
        int ans = 0;
        for(auto x: nums) {
            m[dsu.find(x)]++;
        }
        for(auto x: m) {
            ans = max(ans, x.second);
        }
        return ans;
    }
};