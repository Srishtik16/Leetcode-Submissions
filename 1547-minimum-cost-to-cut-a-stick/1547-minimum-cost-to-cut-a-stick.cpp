class Solution {
public:
    long long recurse(vector<int> &a, vector<vector<long long>> &dp, int i, int j) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        long long ans = LLONG_MAX;
        for(int k = i; k <= j; k++) {
            long long moves = abs(a[j + 1] - a[i - 1]) + recurse(a, dp, i, k - 1) + recurse(a, dp, k + 1, j);
            ans = min(ans, moves);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<long long>> dp(len + 1, vector<long long>(len + 1, -1));
        return recurse(cuts, dp, 1, len);
    }
};