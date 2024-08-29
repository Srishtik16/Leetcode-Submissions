class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> indexes;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            indexes[s[i]].push_back(i);
        }
        auto check = [&](string pattern) {
            int curr = -1;
            for(char c: pattern) {
                auto it = upper_bound(indexes[c].begin(), indexes[c].end(), curr);
                if(it == indexes[c].end()) {
                    return false;
                }
                curr = *it;
            }
            return true;
        };
        int ans = 0;
        for(auto word: words) {
            ans += check(word);
        }
        return ans;
    }
};