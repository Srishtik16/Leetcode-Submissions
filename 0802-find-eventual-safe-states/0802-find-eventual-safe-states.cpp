class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> edgeList;
        for(int i = 0; i < n; i++) {
            for(auto x: graph[i]) {
                edgeList.push_back({x, i});
            }
        }
        graph.clear();
        graph.resize(n);
        vector<int> indegree(n);
        for(auto x: edgeList) {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto x: graph[u]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};