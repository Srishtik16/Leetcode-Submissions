class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ilo = 0, ihi = 0, sumlo = 0, sumhi = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            sumlo += nums[i];
            sumhi += nums[i];
            while(ilo < i && sumlo > goal) {
                sumlo -= nums[ilo];
                ilo++;
            }
            while(ihi < i && (sumhi > goal || (sumhi == goal && nums[ihi] == 0))) {
                sumhi -= nums[ihi];
                ihi++;
            }
            if(sumlo == goal) {
                ans += abs(ihi - ilo) + 1;
            }
        }
        return ans;
    }
};
