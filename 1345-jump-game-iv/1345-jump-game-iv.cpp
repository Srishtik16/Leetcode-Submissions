class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int steps = 0;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int u = q.front();
                q.pop();
                if(u == n - 1) {
                    return steps;
                }
                if(u - 1 >= 0 && !vis[u - 1]) {
                    vis[u - 1] = true;
                    q.push(u - 1);
                }
                if(u + 1 < n && !vis[u + 1]) {
                    vis[u + 1] = true;
                    q.push(u + 1);
                }
                for(auto x: m[arr[u]]) {
                    if(!vis[x]) {
                        vis[x] = true;
                        q.push(x);
                    }
                }
                m[arr[u]].clear();
            }
            steps++;
        }
        return -1;
    }
};