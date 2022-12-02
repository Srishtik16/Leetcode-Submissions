class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n != m) {
            return false;
        }
        array<int, 26> m1, m2;
        for(int i = 0; i < 26; i++) {
            m1[i] = m2[i] = 0;
        }
        for(char c: word1) {
            m1[c - 'a']++;
        }
        for(char c: word2) {
            m2[c - 'a']++;
        }
        sort(word1.begin(), word1.end(), [&](const auto &x, const auto &y) {
            if(m1[x - 'a'] == m1[y - 'a']) {
                return x < y;
            }
            return m1[x - 'a'] < m1[y - 'a'];
        });
        sort(word2.begin(), word2.end(), [&](const auto &x, const auto &y) {
            if(m2[x - 'a'] == m2[y - 'a']) {
                return x < y;
            }
            return m2[x - 'a'] < m2[y - 'a'];
        });
        for(int i = 0; i < n; i++) {
            if(m1[word1[i] - 'a'] != m2[word2[i] - 'a']) {
                return false;
            }
            if(m1[word2[i] - 'a'] == 0) {
                return false;
            }
            if(m2[word1[i] - 'a'] == 0) {
                return false;
            }
        }
        return true;
    }
};