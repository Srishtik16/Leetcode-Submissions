class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        stack<int> s;
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[i] > nums[s.top()]) {
                dp[i] = max(dp[i] + 1, dp[s.top()]);
                s.pop();
            }
            s.push(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};