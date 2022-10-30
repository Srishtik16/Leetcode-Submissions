class Solution {
public:
    int numDecodings(string s) {
        if(s.front() == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(s[i - 1] >= '1' && s[i - 1] <= '9') {
                dp[i] += dp[i - 1];
            }
            string st = "";
            st += s[i - 2];
            st += s[i - 1];
            int val = stoll(st);
            if(val >= 10 && val <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};