class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> m;
        int pref = 0, n = (int)nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            pref += nums[i];
            if(((pref % k) + k) % k == 0) {
                ans++;
            }
            if(m.find((((pref - k) % k) + k) % k) != m.end()) {
                ans += m[(((pref - k) % k) + k) % k];
            }
            m[((pref % k) + k) % k]++;
        }
        return ans;
    }
};