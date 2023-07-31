public class Solution {
    public int MinimumDeleteSum(string s1, string s2) {
        int n = s1.Length;
        int m = s2.Length;
        int[ , ] dp = new int[n + 1, m + 1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i, j] = dp[i - 1, j - 1] + 2 * s1[i - 1];
                }
                else {
                    dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]);
                }
            }
        }
        int sum = 0;
        foreach(char c in s1) {
            sum += c;
        }
        foreach(char c in s2) {
            sum += c;
        }
        return sum - dp[n, m];
    }
}