class Solution {
public:
    vector<int> dp;
    bool recurse(int index, string &s, vector<string> &dict) {
        if(index >= s.size()) {
            return true;
        }
        if(dp[index] != -1) {
            return dp[index] == 0 ? false : true;
        }
        for(int i = index + 1; i <= s.size(); i++) {
            string st = s.substr(index, i - index);
            if(find(dict.begin(), dict.end(), st) != dict.end()) {
                if(recurse(i, s, dict)) {
                    return true;
                }
                else {
                    dp[i] = 0;
                }
            }
        }
        dp[index] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp.assign(n + 1, -1);
        return recurse(0, s, wordDict);
    }
};