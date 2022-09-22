class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        s += " ";
        string word = "";
        for(char c: s) {
            if(c == ' ') {
                reverse(word.begin(), word.end());
                words.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }
        s = "";
        for(auto x: words) {
            s += x;
            s += " ";
        }
        s.pop_back();
        return s;
    }
};