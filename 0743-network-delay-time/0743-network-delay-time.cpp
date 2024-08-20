class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto x: times) {
            vector<int> to = {x[1] - 1, x[2]};
            adj[x[0] - 1].push_back(to);
        }
        k--;
        vector<int> d(n, INT_MAX);
        set<vector<int>> s;
        s.insert({0, k});
        d[k] = 0;
        while(!s.empty()) {
            int node = (*s.begin())[1];
            s.erase(s.begin());
            for(auto child: adj[node]) {
                int to = child[0];
                int weight = child[1];
                if(d[to] > d[node] + weight) {
                    s.erase({d[to], to});
                    d[to] = d[node] + weight;
                    s.insert({d[to], to});
                }
            }
        }
        int mx = *max_element(d.begin(), d.end());
        return mx == INT_MAX ? -1 : mx;
    }
};