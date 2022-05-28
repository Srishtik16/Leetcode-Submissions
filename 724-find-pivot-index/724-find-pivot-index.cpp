class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        vector<int> pref(n, 0), suff(n, 0);
        pref[0] = nums[0], suff[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i]; 
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(suff[i + 1] == 0) {
                    return i;
                }
            }
            else if(i == n - 1) {
                if(pref[i - 1] == 0) {
                    return i;
                }
            }
            else {
                if(pref[i - 1] == suff[i + 1]) {
                    return i;
                }
            }
        }
        return -1;
    }
};