class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int, int> m;
        int pref = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            pref += nums[i];
            if(pref == goal) {
                ans++;
            }
            if(m.find(pref - goal) != m.end()) {
                ans += m[pref - goal];
            }
            m[pref]++;
        }
        return ans;
    }
};