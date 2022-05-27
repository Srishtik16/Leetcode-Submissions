using ll = int;
const ll MaxN = 2e5 + 5;
class DSU {
public:
    ll sizes[MaxN], parent [MaxN];
    void make_set(ll n)
    {
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
            sizes[i] = 1;
        }
    }
    ll find_set(ll node)
    {
        if(parent[parent[node]] != parent[node])
        return parent[node] = find_set(parent[node]);
        else
        return parent[node];
    }
    void union_sets(ll a, ll b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a != b)
        {
            if(sizes[a] < sizes[b])
            swap(a, b);
            parent[b] = a;
            sizes[a] += sizes[b];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu;
        dsu.make_set(1001);
        for(auto x: edges) {
            if(dsu.find_set(x[0]) != dsu.find_set(x[1])) {
                dsu.union_sets(x[0], x[1]);
            }
            else {
                return x;
            }
        }
        return {-1, -1};
    }
};