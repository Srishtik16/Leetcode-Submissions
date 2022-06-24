class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] * nums[i];
        }
        vector<int> suff(n, 1);
        suff[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i];
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans.push_back(suff[i + 1]);
            }
            else if(i == n - 1) {
                ans.push_back(pref[i - 1]);
            }
            else {
                ans.push_back(pref[i - 1] * suff[i + 1]);
            }
        }
        return ans;
    }
};