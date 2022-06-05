class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> m;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            m[s[i]].push_back(i);
        }
        auto check = [&](string pat) {
            int curr = -1;
            for(char c: pat) {
                auto it = upper_bound(m[c].begin(), m[c].end(), curr);
                if(it == m[c].end()) {
                    return false;
                }
                curr = *it;
            }
            return true;
        };
        int ans = 0;
        for(auto &word: words) {
            ans += check(word);
        }
        return ans;
    }
};