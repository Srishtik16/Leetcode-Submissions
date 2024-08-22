class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        map<string, bool> vis;
        q.push(beginWord);
        vis[beginWord] = true;
        int d = 0;
        auto isValid = [&](string w) {
            return vis[w] == false && s.find(w) != s.end();
        };
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                string currWord = q.front();
                string copyWord = currWord;
                q.pop();
                if(currWord == endWord) {
                    return d + 1;
                }
                for(int i = 0; i < (int)currWord.size(); i++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(copyWord[i] == c) {
                            continue;
                        }
                        copyWord[i] = c;
                        if(isValid(copyWord)) {
                            vis[copyWord] = true;
                            q.push(copyWord);
                        }
                        copyWord[i] = currWord[i];
                    }
                }
            }
            d++;
        }
        return 0;
    }
};