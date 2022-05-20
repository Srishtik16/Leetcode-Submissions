class Solution {
public:
    bool isPalin(string s, int start, int end) {
        string str = "";
        for(int i = start; i <= end; i++) {
            str += s[i];
        }
        string t = str;
        reverse(t.begin(), t.end());
        return t == str;
    }
    void recurse(vector<vector<string>> &ans, vector<string> &aux, string s, int index) {
        if(index == s.size()) {
            ans.push_back(aux);
            return;
        }
        for(int i = index; i < (int)s.size(); i++) {
            if(isPalin(s, index, i)) {
                aux.push_back(s.substr(index, i - index + 1));
                recurse(ans, aux, s, i + 1);
                aux.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> aux;
        recurse(ans, aux, s, 0);
        return ans;
    }
};