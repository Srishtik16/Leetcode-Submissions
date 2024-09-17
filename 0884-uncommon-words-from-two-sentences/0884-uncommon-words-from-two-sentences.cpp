class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> f, s;
        string ss = "";
        for(char c: s1) {
            if(c == ' ') {
                f[ss]++;
                ss = "";
            }
            else {
                ss += c;
            }
        }
        f[ss]++;
        ss = "";
        for(char c: s2) {
            if(c == ' ') {
                s[ss]++;
                ss = ""; 
            }
            else {
                ss += c;
            }
        }
        s[ss]++;
        vector<string> ans;
        for(auto x: f) {
            if(x.second == 1 && s[x.first] == 0) {
                ans.push_back(x.first);
            }
        }
        for(auto x: s) {
            if(x.second == 1 && f[x.first] == 0) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};