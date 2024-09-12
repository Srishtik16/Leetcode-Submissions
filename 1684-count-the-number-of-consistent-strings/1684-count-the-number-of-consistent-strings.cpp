class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> allow(allowed.begin(), allowed.end());
        int ans = 0;
        for(auto &x: words) {
            bool ok = false;
            for(char c: x) {
                if(allow.find(c) == allow.end()) {
                    ok = true;
                    break;
                }
            }
            ans += !ok;
        }
        return ans;
    }
};