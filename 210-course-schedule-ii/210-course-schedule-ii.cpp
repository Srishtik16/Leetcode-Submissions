class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n + 1, 0);
        vector<vector<int>> vec(n + 1);
        for(auto x: edges) {
            inDeg[x[1]]++;
            vec[x[0]].push_back(x[1]);
        }
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < n; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            auto u = q.front();
            topo.push_back(u);
            q.pop();
            for(auto x: vec[u]) {
                inDeg[x]--;
                if(inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }
        if(topo.size() != n) {
            topo.clear();
            return topo;
        }
        else {
            reverse(topo.begin(), topo.end());
            return topo;
        }
    }
};