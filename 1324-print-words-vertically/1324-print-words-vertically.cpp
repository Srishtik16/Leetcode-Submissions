class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        vector<string> words;
        string word = "";
        for(char c: s) {
            if(c == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }
        words.push_back(word);
        for(auto &x: words) {
            while(x.size() != 205) {
                x += " ";
            }
        }
        int n = words.size(), m = words[0].size();
        for(int i = 0; i < m; i++) {
            string vertical = "";
            for(int j = 0; j < n; j++) {
                vertical += words[j][i];
            }
            while(!vertical.empty() && vertical.back() == ' ') {
                vertical.pop_back();
            }
            ans.push_back(vertical);
        }
        while(!ans.empty() && ans.back() == "") {
            ans.pop_back();
        }
        return ans;
    }
};