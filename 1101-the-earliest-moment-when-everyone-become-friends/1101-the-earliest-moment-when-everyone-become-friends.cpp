class DSU {
public:
    vector<int> sizes, par;
    int components;
    DSU(int n) {
        components = n;
        sizes.assign(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int find_set(int node) {
        if(node != par[node]) {
            return par[node] = find_set(par[node]);
        }
        else {
            return par[node];
        }
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a != b) {
            components--;
            if(sizes[a] < sizes[b]) {
                swap(a, b);
            }
            sizes[a] += sizes[b];
            sizes[b] = sizes[a];
            par[b] = a;
        }
    } 
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        bool ok = false;
        DSU dsu(n);
        int ans = 0;
        for(auto x: logs) {
            ans = max(ans, x[0]);
            cout << x[1] << " " << x[2] << endl;
            cout << dsu.components << endl;
            dsu.union_sets(x[1], x[2]);
            if(dsu.components == 1) {
                ok = true;
                break;
            }
        }
        if(!ok) {
            ans = -1;
        }
        return ans;
    }
};