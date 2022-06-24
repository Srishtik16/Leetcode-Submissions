class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, product = 1, ans = 0;
        for(int i = 0; i < n; i++) {
            product *= nums[i];
            while(product >= k && l <= i) {
                product /= nums[l];
                l++;
            }
            ans += i - l + 1;
        }
        return ans;
    }
};