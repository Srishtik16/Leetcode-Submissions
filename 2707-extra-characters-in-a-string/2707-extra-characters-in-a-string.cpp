class Solution {
public:
    vector<int> dp;
    int recurse(int index, string &s, vector<string> &dictionary) {
        if(index == s.size()) {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int ans = recurse(index + 1, s, dictionary) + 1; // skip current character
        for(int end = index; end < s.size(); end++) {
            string ss = s.substr(index, end - index + 1);
            if(find(dictionary.begin(), dictionary.end(), ss) != dictionary.end()) {
                ans = min(ans, recurse(end + 1, s, dictionary));
            }
        }
        return dp[index] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        // dp[i] = min chars to be deleted if consider s[i.....n]
        // we can skip i th character and solve for dp(i + 1) + 1
        // Or we can take substr from [i....j] if valid and solve dp[j + 1]
        // answer = min of all these cases
        dp = vector<int>(s.size(), -1);
        return recurse(0, s, dictionary);
    }
};