class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        auto check = [&](int pairs) {
            int count = 0;
            for(int i = 0; i < n - 1; i++) {
                if(nums[i + 1] - nums[i] <= pairs) {
                    count++;
                    i++;
                }
            }
            return count >= p;
        };
        int l = 0, r = nums.back() - nums.front(), ans = 0;
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