class Solution {
public:
    vector<int> bfs(vector<int> adj[], int s, int n, int target) {
        queue<int> q;
        vector<bool> used(n + 1);
        vector<int> d(n + 1), p(n + 1);

        q.push(s);
        used[s] = true;
        p[s] = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }
        vector<int> path;
        while(p[target] != -1) {
            path.push_back(target);
            target = p[target];
        }
        path.push_back(target);
        reverse(path.begin(), path.end());
        return path;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> vec[n + 1];
        for(auto x: edges) {
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);
        }
        if(target == 1) {
            if(t == 0 || vec[1].size() == 0) {
                return 1.0;
            }
            else {
                return 0.0;
            }
        }
        auto path = bfs(vec, 1, n, target);
        vec[1].push_back(-1);
        if(path.size() > t + 1) {
            return 0.0;
        }
        double ans = 1.0;
        if(path.size() < t + 1) {
            if(vec[target].size() > 1) {
                return 0.0;
            }
            path.pop_back();
            for(auto x: path) {
                ans *= (1.0 / (vec[x].size() - 1));
            }
        }
        else {
            path.pop_back();
            for(auto x: path) {
                ans *= (1.0 / (vec[x].size() - 1));
            }
        }
        return ans;
    }
};