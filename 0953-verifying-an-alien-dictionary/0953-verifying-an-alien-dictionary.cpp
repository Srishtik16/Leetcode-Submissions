class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, char> mapped;
        char ch = 'a';
        for(int i = 0; i < 26; i++) {
            mapped[order[i]] = ch++;
        }
        for(auto &x: words) {
            for(char &c: x) {
                c = mapped[c];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};