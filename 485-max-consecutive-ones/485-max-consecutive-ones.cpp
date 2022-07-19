class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        if(count(nums.begin(), nums.end(), 1) == 0) {
            return 0;
        }
        int ans = 0, cnt = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] && nums[i] == 1) {
                cnt++;
            }
            else {
                ans = max(ans, cnt + 1);
                cnt = 0;
            }
        }
        return ans;
    }
};