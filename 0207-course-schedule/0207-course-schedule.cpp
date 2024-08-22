class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> path; // needs to lie on same path (that makes it separate from undirected case)
    bool cycle;
    void dfs(int node) {
        vis[node] = true;
        path[node] = 1;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x);
            } 
            if(vis[x] && path[x]) {
                cycle = true;
            }
        }
        path[node] = 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.clear();
        vis.clear();
        path.clear();
        adj.resize(numCourses);
        vis.resize(numCourses);
        path.resize(numCourses);
        for(auto x: prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        cycle = false;
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        return !cycle;
    }
};