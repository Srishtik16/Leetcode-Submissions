class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(auto x: nums) {
            if(s.find(x - 1) != s.end()) {
                continue;
            }
            int len = 0, val = x;
            while(s.find(val) != s.end()) {
                val++;
                len++;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};