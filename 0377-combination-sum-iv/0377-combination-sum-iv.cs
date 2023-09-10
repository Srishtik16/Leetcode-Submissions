public class Solution {
    public int CombinationSum4(int[] nums, int target) {
        int n = nums.Length;
        List<long> dp = new List<long>(new long[target + 1]);
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(int j = 0; j < n; j++) {
                if(i - nums[j] >= 0) {
                    if(dp[i] >= (long)1e10) {
                        break;
                    }
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return (int)dp[target];
    }
}