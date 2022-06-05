class Solution {
public:
    void dfs(int node, vector<int> vec[], vector<bool> &vis) {
        vis[node] = true;
        for(auto x: vec[node]) {
            if(!vis[x]) {
                dfs(x, vec, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vec[n];
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) {
                    vec[i].push_back(j);
                    vec[j].push_back(i);
                }
            }
        }
        int cc = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cc++;
                dfs(i, vec, vis);
            }
        }
        return cc;
    }
};