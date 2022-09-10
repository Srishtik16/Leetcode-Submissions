class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n, 0);
        pref[0] = nums[0] == 0;
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (nums[i] == 0);
        }
        auto count = [&](int l, int r) {
            if(l > r || r < 0) {
                return 0;
            }
            if(l == 0) {
                return pref[r];
            }
            else {
                return pref[r] - pref[l - 1];
            }
        };
        int l = 0, r = n, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            bool ok = false;
            int left = 0, right = mid - 1;
            while(right < n) {
                int numZeroes = count(left, right);
                if(numZeroes <= k) {
                    ok = true;
                    break;
                }
                left++;
                right++;
            }
            if(ok) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};