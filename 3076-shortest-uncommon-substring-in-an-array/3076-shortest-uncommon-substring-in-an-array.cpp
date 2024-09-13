class Solution {
public:
    string lex(string s, string t) {
        if(s == "") {
            return t;
        }
        if(t == "") {
            return s;
        }
        if(s.size() > t.size()) {
            return t;
        }
        if(t.size() > s.size()) {
            return s;
        }
        return s < t ? s : t;
    }
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    s += arr[j];
                    s += '$';
                }
            }
            string best = "";
            for(int j = 0; j < arr[i].size(); j++) {
                string st = "";
                for(int k = j; k < arr[i].size(); k++) {
                    st += arr[i][k];
                    if(s.find(st) == string::npos) {
                        best = lex(best, st);
                    }
                }
            }
            ans.push_back(best);
        }
        return ans;
    }
};