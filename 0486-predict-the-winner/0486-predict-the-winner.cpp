class Solution {
public:
    vector<vector<int>> dp;
    int recurse(int l, int r, vector<int> &nums) {
        if(l == r) {
            return nums[r];
        }
        if(l > r) {
            return 0;
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int takeLeft = nums[l] - recurse(l + 1, r, nums);
        int takeRight = nums[r] - recurse(l, r - 1, nums);
        return dp[l][r] = max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        // dp[l][r] = balance score when game is played on [l, r]
        // dp[i][i] = nums[i]
        // dp[l][r] = max(nums[l] * turn + recurse(l + 1, r, turn ^ 1), nums[r] * turn + recurse(l, r - 1, turn ^ 1))
        dp = vector<vector<int>>(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return recurse(0, nums.size() - 1, nums) >= 0;
    }
};