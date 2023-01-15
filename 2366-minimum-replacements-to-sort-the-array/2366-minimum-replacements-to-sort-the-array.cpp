class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long moves = 0;
        for(int i = n - 1; i >= 1; i--) {
            if(nums[i] >= nums[i - 1]) {
                continue;
            }
            moves += (nums[i - 1] - 1) / nums[i];
            int groups = (nums[i - 1] - 1) / nums[i] + 1;
            nums[i - 1] = nums[i - 1] / groups;
        }
        return moves;
    }
};