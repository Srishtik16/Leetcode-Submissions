class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<long long, long long> m;
        long long pref = 0;
        long long ans = LLONG_MIN;
        for(auto x: nums) {
            int f = x - k;
            int s = x + k;
            pref += x;
            if(m.find(f) != m.end()) {
                ans = max(ans, pref - m[f] + f);
            }
            if(m.find(s) != m.end()) {
                ans = max(ans, pref - m[s] + s);
            }
            if(m.find(x) == m.end()) {
                m[x] = pref;
            }
            else {
                m[x] = min(m[x], pref); 
            }
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};