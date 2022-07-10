class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(auto &x: nums) {
            x %= 2;
        }
        unordered_map<int, int> m;
        int pref = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            pref += nums[i];
            if(pref == k) {
                ans++;
            }
            if(m.find(pref - k) != m.end()) {
                ans += m[pref - k];
            }
            m[pref]++;
        }
        return ans;
    }
};