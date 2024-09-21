class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // mark adjacents with some other colour if not already coloured
        vector<vector<int>> adj(n);
        for(auto x: paths) {
            adj[x[0] - 1].push_back(x[1] - 1);
            adj[x[1] - 1].push_back(x[0] - 1);
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            vector<int> cols(5);
            for(auto x: adj[i]) {
                cols[ans[x]] = 1;
            }
            for(int c = 1; c <= 4;  c++) {
                if(cols[c] != 1) {
                    ans[i] = c;
                }
            }
        }
        return ans;
    }
};