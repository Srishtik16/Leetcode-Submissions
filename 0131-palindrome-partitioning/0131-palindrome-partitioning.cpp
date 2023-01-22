class Solution {
public:
    bool isPalin(string s, int l, int r) {
        if(r >= size(s) || l < 0) {
            return false;
        }
        string st = "";
        for(int i = l; i <= r; i++) {
            st += s[i];
        }
        string t = st;
        reverse(t.begin(), t.end());
        return st == t;
    }
    void backtrack(int index, string &s, vector<string> &ans, vector<vector<string>> &res) {
        if(index > size(s)) {
            return;
        }
        if(index == size(s)) {
            res.push_back(ans);
            return;
        }
        for(int i = index; i < size(s); i++) {
            if(isPalin(s, index, i)) {
                ans.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, s, ans, res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> res;
        backtrack(0, s, ans, res);
        return res;
    }
};