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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                int i1, i2;
                int cnt = 0;
                for(int k = 0; k < (int)strs[i].size(); k++) {
                    if(strs[i][k] != strs[j][k]) {
                        cnt++;
                        if(cnt == 1) {
                            i1 = k;
                        }
                        if(cnt == 2) {
                            i2 = k;
                        }
                    }
                }
                if(cnt == 2) {
                    if(strs[i][i2] == strs[j][i1] && strs[i][i1] == strs[j][i2]) {
                        dsu.union_sets(i, j);
                    }
                }
                else if(strs[i] == strs[j]) {
                    dsu.union_sets(i, j);
                }
            }
        }
        return dsu.components;
    }
};