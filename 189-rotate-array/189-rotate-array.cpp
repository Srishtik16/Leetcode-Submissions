class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) {
            return;
        }
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};