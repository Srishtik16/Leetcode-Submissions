class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int cnt = count(nums.begin(), nums.end(), 0);
        vector<int> ans;
        for(auto x: nums) {
            if(x != 0) {
                ans.push_back(x);
            }
        }
        ans.resize(n);
        return ans;
    }
};