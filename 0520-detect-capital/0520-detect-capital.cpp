class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(char c: word) {
            count += (bool)isupper(c);
        }
        return (count == (int)word.size() || count == 0 || (isupper(word[0]) && count == 1));
    }
};