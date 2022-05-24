class Solution {
public:
    int numSquares(int n) {
        // dp[i] = minimum squares to form sum of n
        vector<int> dp(n + 1, INT_MAX - 1);
        for(int i = 1; i <= n; i++) {
            if((int)sqrtl(i) * (int)sqrtl(i) == i) {
                dp[i] = 1;
            }
        }
        vector<int> squares;
        for(int i = 1; i <= n; i++) {
            squares.push_back(i * i);
        }
        for(int i = 2; i <= n; i++) {
            for(auto x: squares) {
                if(i - x < 0) {
                    break;
                }
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
        return dp.back();
    }
};