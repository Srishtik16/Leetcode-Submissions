class Solution {
public:
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> revAdj(n);
        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            revAdj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        vector<bool> vis(n);
        q.push(0);
        vis[0] = true;
        int edgeCount = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int u = q.front();
                q.pop();
                for(auto x: adj[u]) {
                    if(!vis[x]) {
                        vis[x] = true;
                        edgeCount++;
                        q.push(x);
                    }
                }
                for(auto x: revAdj[u]) {
                    if(!vis[x]) {
                        vis[x] = true;
                        q.push(x);
                    }
                }
            }
        }
        return edgeCount;
    }
};