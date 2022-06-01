class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        return pref;
    }
};