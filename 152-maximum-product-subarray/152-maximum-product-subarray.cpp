class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        int maxSoFar = nums[0];
        for(int i = 1; i < n; i++) {
            int temp = maxEndingHere * nums[i];
            maxEndingHere = max({minEndingHere * nums[i], temp, nums[i]});
            minEndingHere = min({minEndingHere * nums[i], temp, nums[i]});
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};