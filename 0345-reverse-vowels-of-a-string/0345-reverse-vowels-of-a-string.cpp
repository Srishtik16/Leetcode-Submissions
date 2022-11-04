class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        auto isVowel = [&](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        vector<int> indices;
        string st = "";
        for(int i = 0; i < n; i++) {
            if(isVowel(s[i])) {
                st += s[i];
                indices.push_back(i);
            }
        }
        reverse(indices.begin(), indices.end());
        int ptr = 0;
        for(auto x: indices) {
            s[x] = st[ptr];
            ptr++;
        }
        return s;
    }
};