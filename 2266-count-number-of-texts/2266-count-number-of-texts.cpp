const int MOD = 1e9 + 7;
class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        // dp[i] = number of possible text messages with 1st i characters
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 4; j++) {
                if(i - j >= 0) {
                    string s = "";
                    for(int k = i - j + 1; k <= i; k++) {
                        s += pressedKeys[k - 1];
                    }
                    sort(s.begin(), s.end());
                    if(s.front() != s.back()) {
                        continue;
                    }
                    if(s.size() == 4 && s.front() != '7' && s.front() != '9') {
                        continue;
                    }
                    dp[i] += dp[i - j];
                    dp[i] %= MOD;
                }
            }
        }
        return dp.back();
    }
};