class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans += pref[i] >= sum - pref[i];
        }
        return ans;
    }
};