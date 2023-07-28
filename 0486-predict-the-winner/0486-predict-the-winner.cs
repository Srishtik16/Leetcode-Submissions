public class Solution {
    int[ , ]dp;
    int recurse(int[] nums, int n, int l, int r) {
        if(l == r) {
            return nums[l];
        }
        if(dp[l, r] != -1) {
            return dp[l, r];
        }
        int left = nums[l] - recurse(nums, n, l + 1, r);
        int right = nums[r] - recurse(nums, n, l, r - 1);
        return dp[l, r] = Math.Max(left, right);
    }
    public bool PredictTheWinner(int[] nums) {
        int n = nums.Length;
        dp = new int[n + 1, n + 1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i, j] = -1;
            }
        }
        return recurse(nums, n, 0, n - 1) >= 0;
    }
}