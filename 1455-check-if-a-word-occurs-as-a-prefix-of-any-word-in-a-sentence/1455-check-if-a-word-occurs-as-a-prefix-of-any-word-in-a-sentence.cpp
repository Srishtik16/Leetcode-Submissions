class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence += " ";
        vector<string> words;
        string word = "";
        for(char c: sentence) {
            if(c == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }
        auto search = [&](string word) {
            if(word.size() < searchWord.size()) {
                return false;
            }
            int n = searchWord.size();
            for(int i = 0; i < n; i++) {
                if(searchWord[i] != word[i]) {
                    return false;
                }
            }
            return true;
        };
        for(int i = 0; i < (int)words.size(); i++) {
            if(search(words[i])) {
                return i + 1;
            }
        }
        return -1;
    }
};