public class Solution {
    public double SoupServings(int n) {
        int m = (int)Math.Ceiling(n / 25.0);
        Dictionary<int, Dictionary<int, double>> dp = new Dictionary<int, Dictionary<int, double>>();

        Func<int, int, double> calculateDP = null;
        calculateDP = (i, j) => {
            if (i <= 0 && j <= 0) {
                return 0.5;
            }
            if (i <= 0) {
                return 1;
            }
            if (j <= 0) {
                return 0;
            }
            if (dp.ContainsKey(i) && dp[i].ContainsKey(j)) {
                return dp[i][j];
            }
            if (!dp.ContainsKey(i)) {
                dp[i] = new Dictionary<int, double>();
            }
            return dp[i][j] = (calculateDP(i - 4, j) + calculateDP(i - 3, j - 1) +
                               calculateDP(i - 2, j - 2) + calculateDP(i - 1, j - 3)) / 4;
        };

        for (int k = 1; k <= m; k++) {
            if (calculateDP(k, k) > 1 - 1e-5) {
                return 1;
            }
        }
        return calculateDP(m, m);
    }
}