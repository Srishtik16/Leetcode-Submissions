class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        bool turn = true;
        vector<int> ans;
        while(l <= r) {
            if(turn) {
                ans.push_back(nums[l]);
                l++;
            }
            else {
                ans.push_back(nums[r]);
                r--;
            }
            turn ^= 1;
        }
        return ans;
    }
};