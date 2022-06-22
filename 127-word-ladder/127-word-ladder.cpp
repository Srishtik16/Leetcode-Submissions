class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto check = [&] (string s, string t) {
            int cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                cnt += s[i] != t[i];
            }
            return cnt == 1;
        };
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_map<string, int> d;
        unordered_map<string, bool> vis;
        for(auto x: wordList) {
            d[x] = INT_MAX;
        }
        d[beginWord] = 0;
        vis[beginWord] = true;
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
                        c = cc;
                        if(s.find(aux) != s.end() && !vis[aux]) {
                            vis[aux] = true;
                            d[aux] = min(d[aux], d[u] + 1);
                            q.push(aux);
                        }
                    }
                    c = ch;
                }
            }
            if(vis[endWord]) {
                break;
            }
        }
        return d[endWord] == INT_MAX ? 0 : d[endWord] + 1;
    }
};