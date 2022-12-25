class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        vector<int> ans;
        for(auto x: queries) {
            auto it = upper_bound(nums.begin(), nums.end(), x);
            ans.push_back(distance(nums.begin(), it));
        }
        return ans;
    }
};