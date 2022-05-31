class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> ms1;
        multiset<int, greater<int>> ms2;
        int l = 0, r = 0, ans = 0;
        while(l <= r && r < n) {
            ms1.insert(nums[r]);
            ms2.insert(nums[r]);
            if(abs(*ms1.begin() - *ms2.begin()) <= k) {
                ans = max(ans, r - l + 1);
                r++;
            }
            else {
                ms1.erase(ms1.find(nums[l]));
                ms2.erase(ms2.find(nums[l]));
                l++;
                r++;
            }
        }
        return ans;
    }
};