class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1e16 + 5, ans = 100000000000;
        while(l <= r) {
            long long mid = (l + r) / 2;
            long long ttime = 0;
            for(auto x: time) {
                if(mid / x >= 1e12) {
                    ttime = LLONG_MAX;
                    break;
                }
                ttime += mid / x;
            }
            if(ttime >= totalTrips) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};