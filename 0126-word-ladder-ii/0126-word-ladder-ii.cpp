class Solution {
public:
    void dfs(string node, vector<vector<string>> &paths, vector<string> path, map<string, vector<string>> adj) {
        if(node == "-1") {
            paths.push_back(path);
            return;
        }
        for(auto x: adj[node]) {
            path.push_back(node);
            dfs(x, paths, path, adj);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        map<string, bool> vis;
        q.push(beginWord);
        vis[beginWord] = true;
        map<string, long long> d;
        for(auto x: wordList) {
            d[x] = INT_MAX;
        }
        d[beginWord] = 0;
        auto isValid = [&](string w) {
            return vis[w] == false && s.find(w) != s.end();
        };
        map<string, vector<string>> adj;
        adj[beginWord].push_back("-1");
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                string currWord = q.front();
                string copyWord = currWord;
                q.pop();
                for(int i = 0; i < (int)currWord.size(); i++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(copyWord[i] == c) {
                            continue;
                        }
                        copyWord[i] = c;
                        if(s.find(copyWord) != s.end() && d[copyWord] > d[currWord] + 1) {
                            vis[copyWord] = true;
                            q.push(copyWord);
                            d[copyWord] = d[currWord] + 1;
                            adj[copyWord].clear();
                            adj[copyWord].push_back(currWord);
                        }
                        else if(s.find(copyWord) != s.end() && d[copyWord] == d[currWord] + 1) {
                            adj[copyWord].push_back(currWord);
                        }
                        copyWord[i] = currWord[i];
                    }
                }
            }
        }
        vector<string> path;
        vector<vector<string>> paths;
        dfs(endWord, paths, path, adj);
        for(auto &x: paths) {
            reverse(x.begin(), x.end());
        }
        return paths;
    }
};