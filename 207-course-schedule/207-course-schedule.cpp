class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> revAdj;
    vector<int> toposort;
    vector<bool> vis;
    void dfs(int node) {
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x);
            }
        }
        toposort.push_back(node);
    }
    void revdfs(int node) {
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                revdfs(x);
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        revAdj.resize(numCourses);
        toposort.clear();
        vis.assign(numCourses, false);
        for(auto &edge: prerequisites) {
            if(edge[0] == edge[1]) {
                return false;
            }
            adj[edge[0]].push_back(edge[1]);
            revAdj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        vis.assign(numCourses, false);
        int countScc = 0;
        for(auto &x: toposort) {
            if(!vis[x]) {
                countScc++;
                revdfs(x);
            }
        }
        return countScc == numCourses;
    }
};