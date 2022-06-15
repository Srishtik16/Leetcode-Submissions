const int MOD = 1e9 + 7;
class Solution {
public:
    int djikstra(int node, vector<vector<pair<long long, long long>>> &vec, int n) {
        vector<long long> ways(n + 1, 0), d(n + 1, LLONG_MAX);
        set<pair<long long, long long>> s;
        s.insert({0, node});
        d[node] = 0;
        ways[node] = 1;
        while(!s.empty()) {
            int u = (*s.begin()).second;
            long long dist = (*s.begin()).first;
            s.erase(s.begin());
            for(auto x: vec[u]) {
                if(d[u] + x.first < d[x.second]) {
                    d[x.second] = min(d[u] + x.first, d[x.second]);
                    ways[x.second] = ways[u];
                    s.insert({d[x.second], x.second});
                }
                else if(dist + x.first == d[x.second]) {
                    d[x.second] = min(dist + x.first, d[x.second]);
                    ways[x.second] += ways[u];
                }
                ways[x.second] %= MOD;
            }
        }
        return ways[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> vec(n + 1);
        for(auto x: roads) {
            vec[x[0]].push_back({x[2], x[1]});
            vec[x[1]].push_back({x[2], x[0]});
        }
        return djikstra(0, vec, n);
    }
};