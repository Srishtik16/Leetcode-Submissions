class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        map<char, int> m;
        m['a'] = 'z';
        m['e'] = 'a';
        m['i'] = 'e';
        m['o'] = 'i';
        m['u'] = 'o';
        auto prev = [&](char c) {
            return m[c];
        };
        int j = 0, ans = 0;
        for(int i = 0; i < n;) {
            map<char, int> count;
            count[word[i]]++;
            for(j = i + 1; j < n && (word[j] == word[j - 1] || word[j - 1] == prev(word[j])); j++) {
                count[word[j]]++;
            }
            if(count.size() == 5) {
                ans = max(ans, j - i);
            }
            i = j;
        }
        return ans;
    }
};