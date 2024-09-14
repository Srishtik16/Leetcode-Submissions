class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int islands = 0, ans = 0;
        for(auto x: nums) {
            if(x == mx) {
                islands++;
            }
            else {
                ans = max(ans, islands);
                islands = 0;
            }
        }
        ans = max(ans, islands);
        return ans;
    }
};