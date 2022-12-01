class Solution {
public:
    int minStartValue(vector<int>& nums) {
        auto check = [&](int x) {
            int sum = x;
            for(auto x: nums) {
                sum += x;
                if(sum < 1) {
                    return false;
                }
            }
            return true;
        };
        int l = 1, r = 1e9, ans = 1;
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