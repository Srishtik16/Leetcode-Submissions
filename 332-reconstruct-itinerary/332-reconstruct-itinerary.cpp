class Solution {
public:
    void dfs(string node, vector<string> &path, map<string, multiset<string>> &m) {
        while(!m[node].empty()) {
            string go = *m[node].begin();
            m[node].erase(m[node].begin());
            dfs(go, path, m);
        }
        path.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> vec;
        for(auto x: tickets) {
            vec[x[0]].insert(x[1]);
        }
        vector<string> path;
        dfs("JFK", path, vec);
        reverse(path.begin(), path.end());
        return path;
    }
};