class Solution {
public:
    vector<string> ans;
    void backtrack(int index, string &res, string &s, int n) {
        if(index == n) {
            ans.push_back(res);
            return;
        }
        if(isdigit(s[index])) {
            res += s[index];
            backtrack(index + 1, res, s, n);
            res.pop_back();
        }
        else {
            res += s[index];
            backtrack(index + 1, res, s, n);
            res.pop_back();
            res += isupper(s[index]) ? tolower(s[index]) : toupper(s[index]);
            backtrack(index + 1, res, s, n);
            res.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        ans.clear();
        string res = "";
        backtrack(0, res, s, size(s));
        return ans;
    }
};