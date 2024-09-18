class Solution {
public:
    vector<vector<int>> adj, revadj;
    vector<int> toposort;
    vector<bool> vis;
    void dfs(int node) {
        vis[node] = true;
        for(auto x: revadj[node]) {
            if(!vis[x]) {
                dfs(x);
            }
        }
        toposort.push_back(node);
    }
    void revdfs(int node) {
        vis[node] = true;
        for(auto x: revadj[node]) {
            if(!vis[x]) {
                revdfs(x);
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // if theres a scc with more than one node, then it implies a cycle
        // Kosaraju's algorithm
        // Reverse the adjacency list
        // Do a toposort of the graph
        // do a dfs in order of toposort
        // each cc is a SCC
        adj = vector<vector<int>>(numCourses);
        revadj = adj;
        toposort.clear();
        vis = vector<bool>(numCourses);
        for(auto x: prerequisites) {
            if(x[0] == x[1]) {
                return false;
            }
            adj[x[1]].push_back(x[0]);
            revadj[x[0]].push_back(x[1]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        vis = vector<bool>(numCourses);
        int sccs = 0;
        for(auto x: toposort) {
            if(!vis[x]) {
                revdfs(x);
                sccs++;
            }
        }
        return sccs == numCourses;
    }
};