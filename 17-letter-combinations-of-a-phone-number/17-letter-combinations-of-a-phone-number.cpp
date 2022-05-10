class Solution {
public:
    void backtrack(vector<string> &ans, string &st, string &s, map<char, string> &m, int ind) {
        if(ind == s.size()) {
            if(st.empty()) {
                return;
            }
            ans.push_back(st);
            return;
        }
        for(char ch: m[s[ind]]) {
            st += ch;
            backtrack(ans, st, s, m, ind + 1);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        string st = "";
        vector<string> ans;
        backtrack(ans, st, s, m, 0);
        return ans;
    }
};