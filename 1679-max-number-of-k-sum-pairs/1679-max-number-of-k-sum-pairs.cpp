class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto x: nums) {
            m[x]++;
        }
        int ans = 0;
        for(auto x: nums) {
            if(k != 2 * x) {
                if(m.find(k - x) != m.end()) {
                    int val = min(m[x], m[k - x]);
                    ans += val;
                    m[x] -= val;
                    m[k - x] -= val;
                }
            }
            else {
                ans += m[x] / 2;
                m[x] %= 2;
            }
        }
        return ans;
    }
};