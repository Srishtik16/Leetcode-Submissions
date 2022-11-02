class Solution {
public:
    int _n;
    vector<int> bfs(vector<vector<int>> &adj, int node) {
        vector<bool> vis(_n, false);
        vector<int> d(_n, INT_MAX);
        d[node] = 0;
        vis[node] = true;
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto x: adj[u]) {
                if(!vis[x]) {
                    vis[x] = true;
                    d[x] = d[u] + 1;
                    q.push(x);
                }
            }
        }
        return d;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if(find(bank.begin(), bank.end(), end) == bank.end() && start != end) {
            return -1;
        }
        int n = bank.size();
        auto check = [&](string s, string t) {
            int cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                cnt += s[i] != t[i];
            }
            return cnt == 1;
        };
        bank.insert(bank.begin(), start);
        n++;
        _n = n;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(check(bank[i], bank[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int index = find(bank.begin(), bank.end(), end) - bank.begin();
        vector<int> d = bfs(adj, 0);
        return d[index] == INT_MAX ? -1 : d[index];
    }
};