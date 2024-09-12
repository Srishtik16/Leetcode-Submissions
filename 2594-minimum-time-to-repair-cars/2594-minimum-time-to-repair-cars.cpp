class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1e14, ans = 0;
        auto check = [&](long long time) {
            long long _cars = cars;
            for(auto &r: ranks) {
                _cars -= floor(sqrtl(time / r));
            }
            return _cars <= 0;
        };
        while(l <= r) {
            long long mid = (l + r) / 2;
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