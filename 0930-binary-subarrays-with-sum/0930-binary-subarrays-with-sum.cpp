class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> m;
        int pref = 0, ans = 0;
        m[0]++;
        for(auto x: nums) {
            pref += x;
            ans += m[pref - goal];
            m[pref]++;
        }
        return ans;
    }
};