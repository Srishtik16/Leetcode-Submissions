class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        map<char, int> m;
        for(char c: s) {
            m[c]++;
        }
        map<int, set<char>> mp;
        for(char c = 'a'; c <= 'z'; c++) {
            if(m[c] == 0) {
                continue;
            }
            mp[m[c]].insert(c);
        }
        int moves = 0;
        for(char c = 'a';c <= 'z'; c++) {
            if(mp[m[c]].size() > 1) {
                while(m[c] > 0 && mp[m[c]].size() > 1) {
                    mp[m[c]].erase(c);
                    m[c]--;
                    mp[m[c]].insert(c);
                    moves++;
                }
            }
        }
        return moves;
    }
};