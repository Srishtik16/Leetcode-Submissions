using ll = long long;
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
    long long findProductSum(vector<ll> A, int n)
    {
        // calculating array sum (a1 + a2  ... + an)
        ll array_sum = 0;
        for (int i = 0; i < n; i++)
            array_sum = array_sum + A[i];

        // calculating square of array sum
        // (a1 + a2 + ... + an)^2
        ll array_sum_square = array_sum * array_sum;

        // calculating a1^2 + a2^2 + ... + an^2
        ll individual_square_sum = 0;
        for (int i = 0; i < n; i++)
            individual_square_sum += A[i]*A[i];

        // required sum is (array_sum_square -
        // individual_square_sum) / 2
        return (array_sum_square - individual_square_sum)/2;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu;
        dsu.make_set(n + 1);
        for(auto x: edges) {
            dsu.union_sets(x[0], x[1]);
        }
        set<ll> s;
        for(int i = 0; i < n; i++) {
            s.insert(dsu.find_set(i));
        }
        if(s.size() <= 1) {
            return 0;
        }
        vector<ll> a;
        for(auto x: s) {
            a.push_back(dsu.sizes[x]);
        }
        return findProductSum(a, a.size());
    }
};