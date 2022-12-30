class Solution {
public:
    vector<vector<int>> graph;
    void dfs(int node, int target, vector<vector<int>> &paths, vector<int> &path) {
        if(node == target) {
            path.push_back(target);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x: graph[node]) {
            path.push_back(node);
            dfs(x, target, paths, path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& _graph) {
        graph = _graph;
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        dfs(0, n - 1, paths, path);
        return paths;
    }
};