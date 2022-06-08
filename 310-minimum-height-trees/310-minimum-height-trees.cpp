class Solution {
public:
    vector<int> bfs(vector<int> adj[], int s, int n) {
        queue<int> q;
        vector<bool> used(n);
        vector<int> d(n), p(n);

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
        return d;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        const int MaxN = 2e4 + 5;
        vector<int> vec[MaxN];
        for(int i = 0; i < edges.size(); i++) {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        auto f = bfs(vec, 0, n);
        int d1 = 0, d2 = 0;
        int mxd = 0;
        for(int i = 0; i < n; i++) {
            if(mxd < f[i]) {
                mxd = f[i];
                d1 = i;
            }
        }
        f = bfs(vec, d1, n);
        mxd = 0;
        for(int i = 0; i < n; i++) {
            if(mxd < f[i]) {
                mxd = f[i];
                d2 = i;
            }
        }
        auto s = bfs(vec, d2, n);
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(mxd % 2 == 0) {
                if(f[i] == mxd / 2 && s[i] == mxd / 2) {
                    ans.push_back(i);
                }
            }
            else {
                if(f[i] == (mxd + 1) / 2 && s[i] == mxd / 2) {
                    ans.push_back(i);
                }
                else if(s[i] == (mxd + 1) / 2 && f[i] == mxd / 2) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};