class Solution {
public:
    int recurse(vector<int> &a, vector<vector<int>> &dp, int i, int j) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        for(int k = i; k <= j; k++) {
            int moves = a[i - 1] * a[k] * a[j + 1] + recurse(a, dp, i, k - 1) + recurse(a, dp, k + 1, j);
            ans = max(ans, moves);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return recurse(nums, dp, 1, n);
    }
};