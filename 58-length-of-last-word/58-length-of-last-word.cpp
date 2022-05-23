class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        s += " ";
        string word = "";
        for(char c: s) {
            if(c == ' ') {
                if(word.empty()) {
                    continue;
                }
                words.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }
        return words.back().size();
    }
};