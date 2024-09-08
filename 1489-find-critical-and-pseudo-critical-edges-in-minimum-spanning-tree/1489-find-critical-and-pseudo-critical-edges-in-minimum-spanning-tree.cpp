struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

template<typename T_edge>
struct kruskal {
    struct edge {
        int a, b;
        T_edge weight;
        int index = -1;
        bool in_tree = false;

        edge() {}

        edge(int _a, int _b, T_edge _weight, int _index = -1) : a(_a), b(_b), weight(_weight), index(_index) {}

        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    union_find UF;
    vector<edge> edges;
    vector<bool> original_in_tree;

    kruskal(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        UF.init(n);
        edges = {};
    }

    void add_edge(int a, int b, T_edge weight) {
        edges.emplace_back(a, b, weight, edges.size());
        original_in_tree.push_back(false);
    }

    template<typename T_sum>
    T_sum solve() {
        sort(edges.begin(), edges.end());
        T_sum total = 0;

        for (edge &e : edges)
            if (UF.unite(e.a, e.b)) {
                total += e.weight;
                e.in_tree = true;
                original_in_tree[e.index] = true;
            }

        return total;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        kruskal<long long> mst(n);
        int m = edges.size();
        int index = 0;
        for(auto &edge: edges) {
            edge.push_back(index++);
        }
        sort(edges.begin(), edges.end(), [&](const auto &x, const auto &y) {
           return x[2] < y[2]; 
        });
        for(auto &edge: edges) {
            mst.add_edge(edge[0], edge[1], edge[2]);
        }
        long long w = mst.solve<long long>();
        vector<int> critical, pseudo;
        vector<vector<int>> edgesCopy = edges;
        for(int i = 0; i < m; i++) {
            kruskal<long long> k(n);
            for(int j = 0; j < m; j++) {
                if(i != j) {
                    k.add_edge(edges[j][0], edges[j][1], edges[j][2]);
                }
            }
            long long ww = k.solve<long long>();
            if(k.UF.components != 1 || ww > w) {
                critical.push_back(edges[i][3]);
            }
            else {
                union_find UF(n);
                long long wt = edges[i][2];
                UF.unite(edges[i][0], edges[i][1]);
                for(int j = 0; j < m; j++) {
                    if(i != j && UF.unite(edges[j][0], edges[j][1])) {
                        wt += edges[j][2];
                    }
                }
                if(wt == w) {
                    pseudo.push_back(edges[i][3]);
                }
            }
        }
        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo);
        return ans;
    }
};