class Solution {
public:
    map<string, vector<string>> adj;
    map<string, bool> vis;
    map<string, int> inDegree;
    vector<string> ans;
    void dfs(string node) {
        vis[node] = true;
        for(auto x: adj[node]) {
            inDegree[x]--;
            if(inDegree[x] == 0) {
                if(vis.find(x) == vis.end()) {
                    dfs(x);
                }
                ans.push_back(x);
            }
        }
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        adj.clear();
        vis.clear();
        inDegree.clear();
        int n = recipes.size();
        for(int i = 0; i < n; i++) {
            for(auto x: ingredients[i]) {
                adj[x].push_back(recipes[i]);
                inDegree[recipes[i]]++;
            }
        }
        for(auto x: supplies) {
            if(vis.find(x) == vis.end()) {
                dfs(x);
            }
        }
        return ans;
    }
};