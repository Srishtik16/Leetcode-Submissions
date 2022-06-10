class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj, int s, int n, int target) {
        queue<int> q;
        vector<bool> used(n + 1);
        vector<int> d(n + 1, 1e9), p(n + 1);

        q.push(s);
        used[s] = true;
        p[s] = -1;
        d[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                    d[u] = min(d[u], d[v] + 1);
                    p[u] = v;
                }
            }
        }
        return d;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if(find(bank.begin(), bank.end(), end) == bank.end() && start != end) {
            return -1;
        }
        bank.insert(bank.begin(), start);
        int n = bank.size();
        vector<vector<int>> vec(n + 1);
        auto check = [&] (string s, string t) {
            int n = s.size();
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += s[i] != t[i];
            }
            return cnt <= 1;
        };
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(check(bank[i], bank[j])) {
                    vec[i].push_back(j);
                    vec[j].push_back(i);
                }
            }
        }
        int target = find(bank.begin(), bank.end(), end) - bank.begin();
        auto d = bfs(vec, 0, n, target);
        for(auto x: d) {
            cout << x << " ";
        }
        cout << endl;
        if(d[target] == 1e9) {
            return -1;
        }
        else {
            return d[target];
        }
    }
};