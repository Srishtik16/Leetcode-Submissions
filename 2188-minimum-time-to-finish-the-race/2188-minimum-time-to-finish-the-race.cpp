class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        // dp[i] = Minimum time to complete i laps
        int n = tires.size();
        // precomp[i][j] = total time to run j laps with tire i
        vector<vector<int>> precomp(n, vector<int>(20, 2e9));
        for(int i = 0; i < n; i++) {
            precomp[i][1] = tires[i][0];
            for(int j = 2; j < 20; j++) {
                if(precomp[i][j - 1] * 1LL * tires[i][1] >= 2e9) {
                    break;
                }
                precomp[i][j] = precomp[i][j - 1] * tires[i][1];
            }
            for(int j = 2; j < 20; j++) {
                if(precomp[i][j] + 0LL + precomp[i][j - 1] >= 2e9) {
                    break;
                }
                precomp[i][j] += precomp[i][j - 1];
            }
        }
        vector<int> dp(numLaps + 1, 2e9);
        for(auto x: tires) {
            dp[1] = min(dp[1], x[0]);
        }
        for(int i = 2; i <= numLaps; i++) {
            if(i < 20) {
                for(int j = 0; j < n; j++) {
                    dp[i] = min(dp[i], precomp[j][i]);
                }
            }
            for(int j = 1; j <= 18; j++) {
                if(i - j >= 0) {
                    dp[i] = min(dp[i], dp[j] + changeTime + dp[i - j]);
                }
            }
        }
        return dp.back();
    }
};