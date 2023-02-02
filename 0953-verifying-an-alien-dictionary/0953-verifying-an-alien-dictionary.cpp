class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<char, 26> mapped;
        char ch = 'a';
        for(int i = 0; i < 26; i++) {
            mapped[order[i] - 'a'] = i;
        }
        for(auto &x: words) {
            for(char &c: x) {
                c = char('a' + mapped[c - 'a']);
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};