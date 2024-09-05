class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;
    int recurse(int i, int j) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        for(int k = i; k <= j; k++) {
            ans = max(ans, nums[k] * nums[i - 1] * nums[j + 1] + recurse(i, k - 1) + recurse(k + 1, j));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& _nums) {
        // f(i, j) = answer [i, j] balloons
        // f(i, j) = f(i, k - 1) + f(k + 1, j) + nums[k] * nums[k - 1] * nums[k + 1]
        // ans = f(0, n - 1)
        nums = _nums;
        int n = nums.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return recurse(1, n);
    }
};