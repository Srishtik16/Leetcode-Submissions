class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string, bool> banned;
        for(auto x: bannedWords) {
            banned[x] = true;
        }
        int cnt = 0;
        for(auto x: message) {
            cnt += banned[x];
        }
        return cnt >= 2;
    }
};