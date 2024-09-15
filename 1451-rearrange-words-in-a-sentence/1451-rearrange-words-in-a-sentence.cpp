class Solution {
public:
    string arrangeWords(string text) {
        text.push_back(' ');
        int n = text.size();
        string s = "";
        vector<pair<string, int>> words;
        int pos = 0;
        for(int i = 0; i < n; i++) {
            if(text[i] == ' ') {
                s[0] = tolower(s[0]);
                words.push_back({s, pos++});
                s = "";
            }
            else {
                s += text[i];
            }
        }
        sort(words.begin(), words.end(), [&](const auto &x, const auto &y) {
            if(x.first.size() == y.first.size()) {
                return x.second < y.second;
            }
            return x.first.size() < y.first.size();
        });
        words[0].first[0] = toupper(words[0].first[0]);
        string ans = "";
        for(auto x: words) {
            ans += x.first + " ";
        }
        ans.pop_back();
        return ans;
    }
};