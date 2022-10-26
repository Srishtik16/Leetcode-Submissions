class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                if(nums[i].size() + nums[j].size() == target.size()) {
                    if(nums[i] + nums[j] == target) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};