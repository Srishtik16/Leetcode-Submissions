class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> m;
        int pref = 0, ans = 0;
        for(auto x: nums) {
            pref += x;
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