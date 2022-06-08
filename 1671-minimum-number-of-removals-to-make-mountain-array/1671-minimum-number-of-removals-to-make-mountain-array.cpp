class Solution {
public:
    vector<int> LIS(vector<int> &a, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(a[i] > a[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> front = LIS(nums, n);
        reverse(nums.begin(), nums.end());
        vector<int> back = LIS(nums, n);
        reverse(back.begin(), back.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(front[i] != 1 && back[i] != 1) {
                ans = max(ans, front[i] + back[i] - 1);
            }
        }
        return n - ans;
    }
};