class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dest(n, 0);
        for(int i = 0; i < n; i++) {
            dest[i] = min(n - 1, i + nums[i]);
        }
        vector<int> pref(n, 0);
        pref[0] = dest[0];
        for(int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], dest[i]);
        }
        for(int i = 1; i < n; i++) {
            int prevDest = pref[i - 1];
            if(prevDest < i) {
                return false;
            }
        }
        return true;
    }
};