class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n, 0), suff(n + 1, 0);
        pref[0] = nums[0];
        long long ans = LLONG_MAX, ind = 0;
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        suff[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + nums[i];
        }
        for(int i = 0; i < n - 1; i++) {
            long long front = pref[i] / (i + 1);
            long long back = suff[i + 1] / (n - i - 1);
            if(abs(front - back) < ans) {
                ans = abs(front - back);
                ind = i;
            }
        }
        if(pref.back() / n < ans) {
            ans = pref.back();
            ind = n - 1;
        }
        return (int)ind;
    }
};