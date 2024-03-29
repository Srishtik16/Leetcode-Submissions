class Solution {
public:
    void backtrack(int index, vector<string> &ans, vector<string> &res, string &s, vector<string> &wordDict) {
        if(index > (int)s.size()) {
            return;
        }
        if(index == (int)s.size()) {
            bool ok = true;
            if(ok) {
                string str = "";
                for(auto x: ans) {
                    str += x;
                    str += " ";
                }
                str.pop_back();
                res.push_back(str);
            }
            return;
        }
        for(int i = index + 1; i <= (int)s.size(); i++) {
            string st = s.substr(index, i - index);
            if(find(wordDict.begin(), wordDict.end(), st) != wordDict.end()) {
                ans.push_back(st);
                backtrack(i, ans, res, s, wordDict);
                ans.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res, ans;
        backtrack(0, ans, res, s, wordDict);
        return res;
    }
};