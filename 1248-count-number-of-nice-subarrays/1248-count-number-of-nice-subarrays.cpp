class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        int pref = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            pref += nums[i] % 2;
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