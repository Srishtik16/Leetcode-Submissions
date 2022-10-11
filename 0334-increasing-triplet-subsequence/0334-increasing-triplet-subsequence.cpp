class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int x = INT_MAX, y = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= x) {
                x = nums[i];
            }
            else if(nums[i] <= y) {
                y = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};