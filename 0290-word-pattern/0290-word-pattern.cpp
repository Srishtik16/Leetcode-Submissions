class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, set<string>> eqv;
        set<char> chars(pattern.begin(), pattern.end());
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
        for(int i = 0; i < (int)pattern.length(); i++) {
            eqv[pattern[i]].insert(words[i]);
        }
        set<string> diffWords;
        bool ok = true;
        for(auto x: eqv) {
            ok &= x.second.size() == 1;
            diffWords.insert(*x.second.begin());
        }
        return ok && (chars.size() == diffWords.size()) && (pattern.size() == words.size());
    }
};