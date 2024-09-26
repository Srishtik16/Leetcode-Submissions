class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // lets solve character by character
        // max hash of a character should be compensated by hash in 1st word
        map<char, int> maxHash;
        for(auto x: words2) {
            map<char, int> m;
            for(char c: x) {
                m[c]++;
            }
            for(auto c: m) {
                maxHash[c.first] = max(maxHash[c.first], m[c.first]);
            }
        }
        vector<string> ans;
        for(auto x: words1) {
            map<char, int> m;
            for(char c: x) {
                m[c]++;
            }
            bool ok = true;
            for(auto c: maxHash) {
                ok &= (m[c.first] >= maxHash[c.first]);
            }
            if(ok) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};