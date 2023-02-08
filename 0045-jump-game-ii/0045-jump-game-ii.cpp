class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        int maxReach = -1, currReach = min(nums[0], n - 1), moves = 0;
        for(int i = 0; i < n; i++) {
            maxReach = max(maxReach, min(i + nums[i], n - 1));
            if(i == currReach) {
                moves++;
                currReach = maxReach;
            }
        }
        return moves;
    }
};