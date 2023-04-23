class Solution {
public:
    int numberOfArrays(string s, int k) {
        int m = s.size();
        int n = to_string(k).size();
        int mod = 1e9 + 7;
        vector<int> dp(m + 1);
        dp[0] = 1;
        for(int start = 0; start < m; start++) {
            if(s[start] == '0') {
                continue;
            }
            for(int end = start; end < m; end++) {
                string currNumber = s.substr(start, end - start + 1);
                if(stoll(currNumber) > k) {
                    break;
                }
                dp[end + 1] = (dp[end + 1] + dp[start]) % mod;
            }
        }
        return dp.back();
    }
};