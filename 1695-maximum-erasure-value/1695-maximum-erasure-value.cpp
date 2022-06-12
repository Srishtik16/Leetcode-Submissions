class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int, int> m;
        vector<int> pref(n, 0);
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                pref[i] = nums[i];
            }
            else {
                pref[i] = pref[i - 1] + nums[i];
            }
        }
        auto getSum = [&](int l, int r) {
            if(l == 0) {
                return pref[r];
            }
            else {
                return pref[r] - pref[l - 1]; 
            }
        };
        int ans = 0;
        bool ok = false;
        while(l <= r && r < n) {
            if(!ok) {
                m[nums[r]]++;
            }
            ok = false;
            if(m.size() == (r - l + 1) && getSum(l, r) > ans) {
                ans = max(ans, getSum(l, r));
                r++;
            }
            else if(m.size() == (r - l + 1)) {
                r++;
            }
            else {
                m[nums[l]]--;
                if(m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
                ok = true;
            }
        }
        return ans;
    }
};