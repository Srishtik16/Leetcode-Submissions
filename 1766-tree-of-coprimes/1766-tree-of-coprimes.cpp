// Warning: LCA uses nearly 170 MB for N = 500,000. If low on memory use memory_rmq_lca.cc or block_rmq_lca.cc instead.
template<typename T, bool maximum_mode = false>
struct RMQ {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};

struct LCA {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end;
    vector<int> tour_list, rev_tour_list;
    vector<int> heavy_root;
    vector<int> heavy_root_depth, heavy_root_parent;  // These two vectors serve purely to optimize `get_kth_ancestor`.
    RMQ<int> rmq;
    bool built = false;

    LCA(int _n = 0) {
        init(_n);
    }

    // Warning: this does not call build().
    LCA(const vector<vector<int>> &_adj) {
        init(_adj);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        tour_list.resize(n);
        heavy_root.resize(n);
        built = false;
    }

    // Warning: this does not call build().
    void init(const vector<vector<int>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int degree(int v) const {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        // Erase the edge to parent.
        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }

        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) -> bool {
            return subtree_size[a] > subtree_size[b];
        });
    }

    int tour;

    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            tour_dfs(child, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }

        tour_end[node] = tour;
    }

    void build(const vector<int> &roots = {}, bool build_rmq = true) {
        depth.assign(n, -1);

        for (int root : roots)
            if (depth[root] < 0)
                dfs(root, -1);

        for (int i = 0; i < n; i++)
            if (depth[i] < 0)
                dfs(i, -1);

        tour = 0;
        euler.clear();
        euler.reserve(2 * n);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }

        assert(int(euler.size()) == 2 * n);
        vector<int> euler_depth;
        euler_depth.reserve(euler.size());

        for (int node : euler)
            euler_depth.push_back(node < 0 ? node : depth[node]);

        if (build_rmq)
            rmq.build(euler_depth);

        euler_depth.clear();
        heavy_root_depth.resize(n);
        heavy_root_parent.resize(n);

        for (int i = 0; i < n; i++) {
            heavy_root_depth[i] = depth[heavy_root[i]];
            heavy_root_parent[i] = parent[heavy_root[i]];
        }

        rev_tour_list = tour_list;
        reverse(rev_tour_list.begin(), rev_tour_list.end());
        built = true;
    }

    pair<int, array<int, 2>> get_diameter() const {
        assert(built);

        // We find the maximum of depth[u] - 2 * depth[x] + depth[v] where u, x, v occur in order in the Euler tour.
        pair<int, int> u_max = {-1, -1};
        pair<int, int> ux_max = {-1, -1};
        pair<int, array<int, 2>> uxv_max = {-1, {-1, -1}};

        for (int node : euler) {
            if (node < 0) break;
            u_max = max(u_max, {depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
            uxv_max = max(uxv_max, {ux_max.first + depth[node], {ux_max.second, node}});
        }

        return uxv_max;
    }

    // Returns the center(s) of the tree (the midpoint(s) of the diameter).
    array<int, 2> get_center() const {
        pair<int, array<int, 2>> diam = get_diameter();
        int length = diam.first, a = diam.second[0], b = diam.second[1];
        return {get_kth_node_on_path(a, b, length / 2), get_kth_node_on_path(a, b, (length + 1) / 2)};
    }

    // Note: returns -1 if `a` and `b` aren't connected.
    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];

        if (a > b)
            swap(a, b);

        return euler[rmq.query_index(a, b + 1)];
    }

    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }

    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }

    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }

    // Returns the child of `a` that is an ancestor of `b`. Assumes `a` is a strict ancestor of `b`.
    int child_ancestor(int a, int b) const {
        assert(a != b && is_ancestor(a, b));

        // Note: this depends on RMQ breaking ties by latest index.
        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        // assert(parent[child] == a && is_ancestor(child, b));
        return child;
    }

    int get_kth_ancestor(int a, int k) const {
        if (k > depth[a])
            return -1;

        int goal = depth[a] - k;

        while (heavy_root_depth[a] > goal)
            a = heavy_root_parent[a];

        return tour_list[tour_start[a] - (depth[a] - goal)];
    }

    int get_kth_node_on_path(int a, int b, int k) const {
        int anc = get_lca(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];

        if (k < 0 || k > first_half + second_half)
            return -1;

        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }

    // Note: this is the LCA of any two nodes out of three when the third node is the root.
    // It is also the node with the minimum sum of distances to all three nodes (the centroid of the three nodes).
    int get_common_node(int a, int b, int c) const {
        // Returns the deepest of the three LCAs; this works because the shallowest two will always be the same.
        return get_lca(a, b) ^ get_lca(b, c) ^ get_lca(c, a);
    }

    // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    // Returns a list of {node, parent} for every node in the subtree sorted by tour index. Runs in O(k log k).
    // Note that all parents also appear as a node in the return value, and `nodes[0].first` is the compressed root.
    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto compare_tour = [&](int a, int b) -> bool { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = int(nodes.size());
        nodes.reserve(2 * k - 1);

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), compare_tour);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result(nodes.size());

        for (int i = 0; i < int(nodes.size()); i++)
            result[i] = {nodes[i], i == 0 ? -1 : get_lca(nodes[i], nodes[i - 1])};

        return result;
    }
};
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> ans;
    void dfs(int node, unordered_map<int, vector<int>> &mapping, LCA &lc, vector<int> &nums) {
        int d = INT_MAX;
        for(auto &x: mapping) {
            if(!x.second.empty() && __gcd(nums[node], x.first) == 1) {
                if(d > lc.get_dist(node, x.second.back())) {
                    ans[node] = x.second.back();
                    d = lc.get_dist(node, x.second.back());
                }
            }
        }
        mapping[nums[node]].push_back(node);
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x, mapping, lc, nums);
            }
        }
        mapping[nums[node]].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        // map values to nodes
        // get closest nodes based on values by binary lifing
        int n = edges.size() + 1;
        LCA lc(n);
        adj.clear();
        adj.resize(n);
        vis.assign(n, false);
        ans.assign(n, -1);
        unordered_map<int, vector<int>> mapping;
        for(auto x: edges) {
            lc.add_edge(x[0], x[1]);
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        lc.build();
        dfs(0, mapping, lc, nums);
        return ans;
    }
};