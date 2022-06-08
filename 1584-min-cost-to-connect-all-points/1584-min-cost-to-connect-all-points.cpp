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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> edges;
        int n = points.size();
        auto dist = [&](auto x, auto y) {
            return abs(x[0] - y[0]) + abs(x[1] - y[1]);
        };
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                edges.push_back({dist(points[i], points[j]), {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu;
        dsu.make_set(n + 1);
        int cost = 0;
        for(auto x: edges) {
            if(dsu.find_set(x.second.first) == dsu.find_set(x.second.second)) {
                continue;
            }
            cost += x.first;
            dsu.union_sets(x.second.first, x.second.second);
        }
        return cost;
    }
};