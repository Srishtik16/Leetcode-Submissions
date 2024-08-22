class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);
        for(auto x: prerequisites) {
            inDeg[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        int sz = 0;
        vector<int> toposort;
        while(!q.empty()) {
            int node = q.front();
            toposort.push_back(node);
            sz++;
            q.pop();
            for(auto x: adj[node]) {
                inDeg[x]--;
                if(inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }
        reverse(toposort.begin(), toposort.end());
        return sz != numCourses ? vector<int>{} : toposort;
    }
};