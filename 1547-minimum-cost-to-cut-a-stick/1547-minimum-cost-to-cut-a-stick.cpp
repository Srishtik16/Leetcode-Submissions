class Solution {
public:
    int recurse(vector<int> &a, vector<vector<int>> &dp, int i, int j) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i; k <= j; k++) {
            int moves = abs(a[j + 1] - a[i - 1]) + recurse(a, dp, i, k - 1) + recurse(a, dp, k + 1, j);
            ans = min(ans, moves);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
        return recurse(cuts, dp, 1, len);
    }
};