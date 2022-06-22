class Solution {
public:
    void dfs(vector<vector<string>> &paths, vector<string> &path, unordered_map<string, vector<string>> &parent, string node) {
        if(node == "-1") {
            paths.push_back(path);
            return;
        }
        for(auto par: parent[node]) {
            path.push_back(node);
            dfs(paths, path, parent, par);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        auto check = [&] (string s, string t) {
            int cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                cnt += s[i] != t[i];
            }
            return cnt == 1;
        };
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_map<string, int> d;
        unordered_map<string, bool> vis;
        for(auto x: wordList) {
            d[x] = INT_MAX;
        }
        unordered_map<string, vector<string>> parent;
        d[beginWord] = 0;
        vis[beginWord] = true;
        parent[beginWord].push_back("-1");
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto u = q.front();
                q.pop();
                string aux = u;
                for(char &c: aux) {
                    char ch = c;
                    for(char cc = 'a'; cc <= 'z'; cc++) {
                        if(cc == ch) {
                            continue;
                        }
                        c = cc;
                        if(s.find(aux) != s.end() && d[aux] > d[u] + 1) {
                            vis[aux] = true;
                            d[aux] = min(d[aux], d[u] + 1);
                            parent[aux].clear();
                            parent[aux].push_back(u);
                            q.push(aux);
                        }
                        else if(s.find(aux) != s.end() && d[aux] == d[u] + 1) {
                            parent[aux].push_back(u);
                        }
                    }
                    c = ch;
                }
            }
        }
        vector<vector<string>> paths;
        vector<string> path;
        dfs(paths, path, parent, endWord);
        for(auto &x: paths) {
            reverse(x.begin(), x.end());
        }
        return paths;
    }
};