class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> prev(n);
        iota(prev.begin(), prev.end(), 0);
        vector<int> dp(n + 1, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        int ind = 0, ans = 0;
        for(int i = 0; i <= n; i++) {
            if(dp[i] > ans) {
                ans = dp[i];
                ind = i;
            }
        }
        vector<int> subset;
        while(prev[ind] != ind) {
            subset.push_back(nums[ind]);
            ind = prev[ind];
        }
        subset.push_back(nums[ind]);
        return subset;
    }
};