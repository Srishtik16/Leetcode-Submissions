class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n);
        suff[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], nums[i]);
        }
        int best = 0;
        for(int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(suff[mid] >= nums[i]) {
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if(ans != -1) {
                best = max(best, ans - i);
            }
        }
        return best;
    }
};