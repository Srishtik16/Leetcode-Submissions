class Solution {
public:
    vector<int> bfs(vector<vector<int>> &redAdj, vector<vector<int>> &blueAdj, int s, int n, bool col) {
        queue<int> q;
        vector<bool> used1(n + 1), used2(n + 1);
        vector<int> d(n + 1, 1e9), p(n + 1);

        q.push(s);
        used1[s] = true;
        used2[s] = true;
        p[s] = -1;
        d[s] = 0;
        bool turn = true;
        int levels = 1;
        while (!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int v = q.front();
                q.pop();
                if(turn ^ col) {
                    for (int u : redAdj[v]) {
                        d[u] = min(d[u], levels);
                        if (!used1[u]) {
                            used1[u] = true;
                            q.push(u);
                            p[u] = v;
                        }
                    }
                }
                else {
                    for (int u : blueAdj[v]) {
                        d[u] = min(d[u], levels);
                        if (!used2[u]) {
                            used2[u] = true;
                            q.push(u);
                            p[u] = v;
                        }
                    }
                }
            }
            turn ^= 1;
            levels++;
        }
        return d;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redAdj(n + 1), blueAdj(n + 1);
        for(auto x: redEdges) {
            redAdj[x[0]].push_back(x[1]);
        }
        for(auto x: blueEdges) {
            blueAdj[x[0]].push_back(x[1]);
        }
        vector<int> d1 = bfs(redAdj, blueAdj, 0, n, true);
        vector<int> d2 = bfs(redAdj, blueAdj, 0, n, false);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            cout << i << " " << d1[i] << " " << d2[i] << endl;
            ans[i] = min(d1[i], d2[i]);
            if(ans[i] == 1e9) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};