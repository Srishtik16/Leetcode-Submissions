class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                if(cnt == 1) {
                    return false;
                }
                cnt++;
                if(i < 1 || nums[i - 1] <= nums[i + 1]) {
                    nums[i] = nums[i + 1];
                }
                else {
                    nums[i + 1] = nums[i];
                }
            }
        }
        return true;
    }
};