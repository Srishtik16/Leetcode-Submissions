class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0;
        for(char c: t) {
            if(c == s[ptr]) {
                ptr++;
            }
        }
        return ptr == s.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&](const auto &x, const auto &y) {
           return x.size() < y.size(); 
        });
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(words[i].size() == words[j].size() + 1 && isSubsequence(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};