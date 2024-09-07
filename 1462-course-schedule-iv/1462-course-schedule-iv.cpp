class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto x: prerequisites) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int node = q.front();
                q.pop();
                for(auto child: adj[node]) {
                    indegree[child]--;
                    dp[node][child] = true;
                    for(int i = 0; i < n; i++) {
                        if(dp[i][node]) {
                            dp[i][child] = true;
                        }
                    }
                    if(indegree[child] == 0) {
                        q.push(child);
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto x: queries) {
            ans.push_back(dp[x[0]][x[1]]);
        }
        return ans;
    }
};