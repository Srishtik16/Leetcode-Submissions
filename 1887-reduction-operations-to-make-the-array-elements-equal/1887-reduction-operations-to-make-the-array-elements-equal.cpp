class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums.back()) {
                break;
            }
            else if(nums[i] == nums[i + 1]) {
                continue;
            }
            else {
                ans += i + 1;
            }
        }
        return ans;
    }
};