public class Solution {
    bool check(int[] dist, int speed, double hour) {
        int n = dist.Length;
        double time = 0.0d;
        for(int i = 0; i < n - 1; i++) {
            time += (dist[i] + speed - 1) / speed;
        }
        time += (dist[n - 1] * 1.0d) / speed;
        return time <= hour;
    }
    public int MinSpeedOnTime(int[] dist, double hour) {
        int l = 1, r = 10000005, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(dist, mid, hour)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
}