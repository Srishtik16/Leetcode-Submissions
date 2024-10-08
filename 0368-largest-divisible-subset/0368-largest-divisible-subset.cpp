class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        vector<int> prev(n, -1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        int index = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> ans;
        while(prev[index] != -1) {
            ans.push_back(nums[index]);
            index = prev[index];
        }
        ans.push_back(nums[index]);
        return ans;
    }
};