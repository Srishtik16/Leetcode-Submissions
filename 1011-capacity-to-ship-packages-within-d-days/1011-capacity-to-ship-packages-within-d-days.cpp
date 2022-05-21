class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = accumulate(weights.begin(), weights.end(), 0LL), ans = 0;
        auto check = [&](int wt) {
            int day = 1, currWeight = 0;
            for(auto x: weights) {
                if(x > wt) {
                    return false;
                }
                currWeight += x;
                if(currWeight > wt) {
                    day++;
                    currWeight = x;
                }
            }
            return day <= days;
        };
        while(l <= r) {
            int mid = (l + r) / 2;
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