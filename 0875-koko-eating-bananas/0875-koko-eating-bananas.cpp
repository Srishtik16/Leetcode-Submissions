using ll = long long;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        auto check = [&](int speed) {
            ll cnt = 0;
            for(auto x: piles) {
                cnt += (x + 0LL + speed - 1) / speed;
            }
            return cnt <= h;
        };
        ll l = 1, r = 1e15 + 5, ans = -1;
        while(l <= r) {
            ll mid = (l + r) / 2;
            if(check(mid)) {
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