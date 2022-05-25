class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0LL), ans = 0;
        auto check = [&](int val) {
            int sum = 0, cnt = 1;
            for(int i = 0; i < n; i++) {
                if(nums[i] > val) {
                    return false;
                }
                sum += nums[i];
                if(sum > val) {
                    cnt++;
                    sum = nums[i];
                }
            }
            return cnt <= m;
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