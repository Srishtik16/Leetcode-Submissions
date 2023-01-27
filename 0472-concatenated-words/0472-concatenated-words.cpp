class Solution {
public:
    vector<int> dp;
    bool recurse(int index, string &s, unordered_set<string> &dict) {
        if(index >= s.size()) {
            return true;
        }
        if(dp[index] != -1) {
            return dp[index] == 0 ? false : true;
        }
        for(int i = index + 1; i <= s.size(); i++) {
            string st = s.substr(index, i - index);
            if(dict.find(st) != dict.end()) {
                if(recurse(i, s, dict)) {
                    dp[i] = 1;
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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        for(auto x: words) {
            dict.erase(x);
            int n = x.size();
            dp.assign(n + 1, -1);
            if(recurse(0, x, dict)) {
                ans.push_back(x);
            }
            dict.insert(x);
        }
        return ans;
    }
};