public class Solution {
    bool check(long mid, int m, int[] batteries) {
        long extra = 0;
        foreach(int x in batteries) {
            extra += Math.Min(x, mid);
        }
        return extra >= (long)m * mid;
    }
    public long MaxRunTime(int m, int[] batteries) {
        int n = batteries.Length;
        long l = 1, r = (long)1e14, ans = -1;
        while(l <= r) {
            long mid = (l + r) / 2;
            if(check(mid, m, batteries)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
}