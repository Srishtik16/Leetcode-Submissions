class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
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